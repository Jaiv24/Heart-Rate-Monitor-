# Author: Jaiv Shah
# Course: CENG355
# This is a python script to get the data from firebase and send it to Arduino IDE 
import pyrebase
import argparse
import datetime
import time

import serial
from serial import Serial

time_str = datetime.datetime.now().strftime("%Y%b%d_%I:%M:%S%p").upper()

ap = argparse.ArgumentParser()
ap.add_argument("-t", "--temp", help="Patient temperature at time of reading") #
ap.add_argument("-r", "--heart", help="Patient heart rate at the time of reading")
args = vars(ap.parse_args())


#firebase configuration
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

user = db.child("HeartRate").get()

for x in user.each():
    date = db.child("HeartRate").child(x.key()).child("HeartRate").get()
    # date = db.child("HeartRate").get()
    print("Heart Rate: " + date.val())
#
userTemp = db.child("Temperature").get()
for x in userTemp.each():
    date = db.child("Temperature").child(x.key()).child("Temperature").get()
    # date = db.child("Temperature").get()
    print("Temperature: " + date.val())

with serial.Serial('COM4', 9600) as ser:
    ser.write((date.val() + '\n').encode())
    y = ser.readline()
    print(y)
    #print(y.replace(b'\n', b'').replace(b'\r', b''))
    ser.close()

# sent data through the port to arduino


