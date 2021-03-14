package com.example.firebaseheartratemonitor;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class AdapterTemp extends RecyclerView.Adapter<AdapterTemp.MyViewHolder> {
    ArrayList<ModelTemp> mlist;
    Context context;

    public AdapterTemp(Context context, ArrayList<ModelTemp> mlist){
        this.mlist = mlist;
        this.context = context;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(context).inflate(R.layout.temp_data, parent , false);
        return new AdapterTemp.MyViewHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
        ModelTemp model = mlist.get(position);
        holder.timeDate2.setText(model.getTimeDate());
        holder.Temperature.setText(model.getTemperature());
    }

    @Override
    public int getItemCount() {
        return mlist.size();
    }

    public static class MyViewHolder extends RecyclerView.ViewHolder{
        TextView Temperature, timeDate2;
        public MyViewHolder(@NonNull View itemView) {
            super(itemView);

            Temperature = itemView.findViewById(R.id.temperature);
            timeDate2 = itemView.findViewById(R.id.timeDate2);
        }
    }
}
