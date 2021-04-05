package com.example.firebaseheartratemonitor;

public class Model
{
    // Variable to store data corresponding
    // to firstname keyword in database

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

}