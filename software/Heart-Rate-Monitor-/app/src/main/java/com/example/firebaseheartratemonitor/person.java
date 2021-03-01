package com.example.firebaseheartratemonitor;

public class person
{
    // Variable to store data corresponding
    // to firstname keyword in database
    private String firstname;



    // Variable to store data corresponding
    // to age keyword in database
    private String heartRate;
    private String temperature;
    // Mandatory empty constructor
    // for use of FirebaseUI
    public person() {}

    // Getter and setter method
    public String getFirstname()
    {
        return firstname;
    }
    public void setFirstname(String firstname)
    {
        this.firstname = firstname;
    }

    public String getTemperature()
    {
        return temperature;
    }
    public void setTemperature  (String temperature)
    {
        this.temperature = temperature;
    }

    public String getHeartRate()
    {
        return heartRate;
    }
    public void setHeartRate(String heartRate)
    {
        this.heartRate = heartRate;
    }
}