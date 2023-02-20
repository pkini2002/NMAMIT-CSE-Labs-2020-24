package com.example.labprogram;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.Context;
import android.content.DialogInterface;
import android.graphics.Color;
import android.os.Bundle;
import android.text.Layout;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    final Context context = this;
    ConstraintLayout lay1;
    Button b;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        lay1=findViewById(R.id.layout);
        b=findViewById(R.id.button);

        b.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                LayoutInflater li=LayoutInflater.from(context);
                View promptsView=li.inflate(R.layout.dialog,null);

                AlertDialog.Builder alertDialogBuilder=new AlertDialog.Builder(context);
                alertDialogBuilder.setView(promptsView);

                alertDialogBuilder.setCancelable(false).setPositiveButton("OK", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        Random r=new Random();
                        int c= Color.rgb(r.nextInt(255),r.nextInt(255),r.nextInt(255));
                        lay1.setBackgroundColor(c);
                    }
                })
                        .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                dialogInterface.cancel();
                            }
                        });

                // Create alert dialog
                AlertDialog alertDialog=alertDialogBuilder.create();
                alertDialog.show();
            }
        });
    }
}
