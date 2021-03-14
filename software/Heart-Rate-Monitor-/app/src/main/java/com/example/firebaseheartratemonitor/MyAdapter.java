package com.example.firebaseheartratemonitor;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;
import com.firebase.ui.database.FirebaseRecyclerAdapter;
import com.firebase.ui.database.FirebaseRecyclerOptions;

import java.util.ArrayList;

// FirebaseRecyclerAdapter is a class provided by
// FirebaseUI. it provides functions to bind, adapt and show
// database contents in a Recycler View
public class MyAdapter extends RecyclerView.Adapter<MyAdapter.MyViewHolder> {
    ArrayList<Model> mlist;
    Context context;

    public MyAdapter(Context context, ArrayList<Model> mlist){
        this.mlist = mlist;
        this.context = context;
    }
    
    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(context).inflate(R.layout.person, parent , false);
        return new MyViewHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
        Model model =mlist.get(position);
        holder.timeDate.setText(model.getTimeDate());
        holder.heartrate.setText(model.getHeartRate());
    }

    @Override
    public int getItemCount() {
        return mlist.size();
    }

    public static class MyViewHolder extends RecyclerView.ViewHolder{
        TextView  heartrate, timeDate;
        public MyViewHolder(@NonNull View itemView) {
            super(itemView);

            heartrate = itemView.findViewById(R.id.heartrate);
            timeDate = itemView.findViewById(R.id.timeDate);
        }
    }
}
