package com.example.firebaseheartratemonitor;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.firebase.ui.database.FirebaseRecyclerOptions;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {


     RecyclerView recyclerView;
     MyAdapter adapter; // Create Object of the Adapter class
     FirebaseDatabase db = FirebaseDatabase.getInstance();
     DatabaseReference mbase = db.getReference().child("HeartRate");
     ArrayList<Model> list;
     Button moveTempDataBtn;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        recyclerView = findViewById(R.id.recycler1);

        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        recyclerView.smoothScrollBy(0,1 );
        list = new ArrayList<>();

        moveTempDataBtn = findViewById(R.id.moveTempDataBtn);

        // Connecting object of required Adapter class to
        // the Adapter class itself
        adapter = new MyAdapter(this, list);
        // Connecting Adapter class with the Recycler view*/
        recyclerView.setAdapter(adapter);

        mbase.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {

                // This Will not give repeating data
                list.clear();
                for (DataSnapshot dataSnapshot : snapshot.getChildren()){
                    Model model = dataSnapshot.getValue(Model.class);
                    list.add(model);
                }
                adapter.notifyDataSetChanged();
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });

        moveTempDataBtn.setOnClickListener(v -> {
            Intent intent = new Intent(MainActivity.this, readTempData.class);
            startActivity(intent);
        });
    }

}