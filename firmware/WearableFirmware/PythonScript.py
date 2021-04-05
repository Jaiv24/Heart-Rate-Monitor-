# Authors: Alexandra Hutan, Jaiv Shah, Kanjav Patel, Pushpinder Kaur
# Course: CENG355
# This is a python script to get the data from firebase and send it to Arduino IDE and sent data
# picked up from the port by the python script and sent into the database
import pyrebase
import argparse
import datetime
import time
import argparse

import ser

time_str = datetime.datetime.now().strftime("%Y%b%d_%I:%M:%S%p").upper()

# mannually inser data into the firebase by running the pythin script: main.py -t 35 -r 78
ap = argparse.ArgumentParser()
ap.add_argument("-t", "--temp", help="Patient temperature at time of reading")
ap.add_argument("-r", "--heart", help="Patient heart rate at the time of reading")
args = vars(ap.parse_args())

# establishing the connection to the firebase
firebaseConfig = {
    "apiKey": "",
    "authDomain": "heartrate-firebase.firebaseapp.com",
    "databaseURL": "https://heartrate-firebase-default-rtdb.firebaseio.com/",
    "projectId": "heartrate-firebase",
    "storageBucket": "heartrate-firebase.appspot.com",
    "messagingSenderId": "851991577466",
    "appId": "1:851991577466:web:daaf323d9af64fd3318cc3",
}


firebase = pyrebase.initialize_app(firebaseConfig)
db = firebase.database()

if args.get("temp", None) is not None:
    data = {"Temperature": args.get("temp", None)}
    db.child("Temperature").child(time_str).set(data)

if args.get("heart", None) is not None:
    data = {"HeartRate": args.get("heart", None)}
    db.child("HeartRate").child(time_str).set(data)


# display data in the firebase
user = db.child("HeartRate").get()
for x in user.each():
    date = db.child("HeartRate").child(x.key()).child("HeartRate").get()
    # date = db.child("HeartRate").get()
    print("Heart Rate: " + date.val())

userTemp = db.child("Temperature").get()
for x in userTemp.each():
    date = db.child("Temperature").child(x.key()).child("Temperature").get()
    # date = db.child("Temperature").get()
    print("Temperature: " + date.val())


while 1:
    # reading temperature from the port
    print("Reading temperature...")
    time.sleep(1)
    ser=ser.Serial("/dev/ttyACM0", 9600)
    x=ser.readline().decode('utf-8')
    time_str = datetime.datetime.now().strftime("%Y%b%d_%I:%M:%S%p").upper()
    print(x)
    time.sleep(1)
    data = {"Temperature" : x }
    db.child("Temperature").child(time_str).set(data)
    time.sleep(1)
    # reading the heart rate from the port
    print("Reading heartrate...")
    read_ser = ser.readline()
    hr2 = read_ser.decode('utf-8')
    print(hr2)
    print("About to send data")
    time.sleep(1)
    data = {
        "HeartRate": hr2,
        "TimeDate": time_str
    }
    db.child("HeartRate").child(time_str).set(data)
    print("Data Sent!")
    time.sleep(1)
    # writing data to the port so it can be picked by the arduino code and sent into the sd card
    try:
        while True:
            dataStr = ser.readline().decode('utf-8').strip()
            print(dataStr)
    except KeyboardInterrupt:
        pass
    print("Closing terminal")
    ser.close()

