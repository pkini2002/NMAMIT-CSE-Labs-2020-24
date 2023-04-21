package com.example.lab_programs;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    Button btn;
    CheckBox chk1,chk2,chk3,chk4;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn=findViewById(R.id.button);
        chk1=findViewById(R.id.checkBox);
        chk2=findViewById(R.id.checkBox2);
        chk3=findViewById(R.id.checkBox3);
        chk4=findViewById(R.id.checkBox4);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                StringBuilder result=new StringBuilder();
                int totalamount=0;
                result.append("The order history is as follows: ");
                if(chk1.isChecked()){
                    result.append("\n Piza-Rs 250");
                    totalamount+=250;
                }

                if(chk2.isChecked()){
                    result.append("\nBurger - Rs 80");
                    totalamount+=80;
                }

                if(chk3.isChecked()){
                    result.append("Pasta - Rs 60");
                    totalamount+=60;
                }

                if(chk4.isChecked()){
                    result.append("Frenchfries - Rs 100");
                    totalamount+=100;
                }
                result.append("\nThe total amount to be paid is: "+totalamount);
                Toast.makeText(getApplicationContext(), result.toString(), Toast.LENGTH_LONG).show();
            }
        });
    }
}
