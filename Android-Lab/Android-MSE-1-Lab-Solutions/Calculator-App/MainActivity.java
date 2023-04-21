// Background Image Changer - Dialog Box Program

package com.example.lab_programs;


import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    EditText t1,t2;
    Button add,sub,mul,div,clear;
    TextView t;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        t1=findViewById(R.id.editText1);
        t2=findViewById(R.id.editText2);

        add=findViewById(R.id.button3);
        sub=findViewById(R.id.button4);
        mul=findViewById(R.id.button5);
        div=findViewById(R.id.button6);
        clear=findViewById(R.id.button7);

        t=findViewById(R.id.textView);

        add.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int n1 = Integer.parseInt(t1.getText().toString());
                int n2 = Integer.parseInt(t2.getText().toString());
                int val=n1+n2;
                t.setText("Addition of 2 numbers is: "+val);
            }
        });

        sub.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int n1 = Integer.parseInt(t1.getText().toString());
                int n2 = Integer.parseInt(t2.getText().toString());
                int val=n1-n2;
                t.setText("Subtraction of 2 numbers is: "+val);
            }
        });

        mul.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int n1 = Integer.parseInt(t1.getText().toString());
                int n2 = Integer.parseInt(t2.getText().toString());
                int val=n1*n2;
                t.setText("Multiplication of 2 numbers is: "+val);
            }
        });

        div.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int n1 = Integer.parseInt(t1.getText().toString());
                int n2 = Integer.parseInt(t2.getText().toString());
                try{
                    int val=n1/n2;
                    t.setText("Division of 2 numbers is: "+val);
                }catch(ArithmeticException e){
                    t.setText("Divide by 0 error!");
                }
            }
        });

        clear.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText("");
                t2.setText("");
                t.setText("");
            }
        });

    }
}
