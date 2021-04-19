package com.example.firebaseheartratemonitor;

public class Model
{
     // Variable to store data corresponding
     String HeartRate;
     String TimeDate;

    public String getTimeDate()
    {
        return TimeDate;
    }

    public String getHeartRate()
    {
        return HeartRate + " bpm";
    }

//    public Float convertedFloatData(){
//        return Float.parseFloat(HeartRate);
//    }
//
//    public Float floatTimeData() {
//        String requiredTimeData = TimeDate.substring(11,15);
//        float timeFloat = Float.parseFloat(requiredTimeData.replace(":","."));
//        return timeFloat;
//    }

}