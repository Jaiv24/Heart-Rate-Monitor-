package com.example.firebaseheartratemonitor;

public class ModelTemp {
    String Temperature;
    String TimeDate;

    public String getTimeDate()
    {
        return TimeDate;
    }

    public String getTemperature()
    {
        return Temperature + "°C";
    }
}
