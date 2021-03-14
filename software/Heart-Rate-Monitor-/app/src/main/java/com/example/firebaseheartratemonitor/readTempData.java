package com.example.firebaseheartratemonitor;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.widget.Button;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.ArrayList;

public class readTempData extends AppCompatActivity {


     RecyclerView recyclerView;
     AdapterTemp adapter; // Create Object of the Adapter class
     FirebaseDatabase db = FirebaseDatabase.getInstance();
     DatabaseReference mbase = db.getReference().child("Temperature");
     ArrayList<ModelTemp> list;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_read_temp_data);

        recyclerView = findViewById(R.id.recycler2);

        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        recyclerView.smoothScrollBy(0,1 );
        list = new ArrayList<>();

        adapter = new AdapterTemp(this, list);
        // Connecting Adapter class with the Recycler view*/
        recyclerView.setAdapter(adapter);

        mbase.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {

                for (DataSnapshot dataSnapshot : snapshot.getChildren()){
                    ModelTemp model = dataSnapshot.getValue(ModelTemp.class);
                    list.add(model);
                }
                adapter.notifyDataSetChanged();
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });
    }
}