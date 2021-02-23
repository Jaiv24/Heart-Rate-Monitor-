package com.example.firebaseheartratemonitor;

public class person
{
    // Variable to store data corresponding
    // to firstname keyword in database
    private String firstname;



    // Variable to store data corresponding
    // to age keyword in database
    private String measuredValue;

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
    
    public String getMeasuredValue()
    {
        return measuredValue;
    }
    public void setMeasuredValue(String measuredValue)
    {
        this.measuredValue = measuredValue;
    }
}