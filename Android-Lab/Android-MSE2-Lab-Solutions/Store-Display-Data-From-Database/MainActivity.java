package com.example.mse2android;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    Button b1,b2;
    EditText t1,t2,t3;

    SQLiteDatabase db=null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        t1=findViewById(R.id.editTextTextPersonName);
        t2=findViewById(R.id.editTextTextPersonName2);
        t3=findViewById(R.id.editTextTextPersonName3);
        b1=findViewById(R.id.button);
        b2=findViewById(R.id.button2);
        b1.setOnClickListener(this);
        b2.setOnClickListener(this);
    }

    @SuppressLint("range")
    @Override
    public void onClick(View view) {
            String name,age,email;
            name=t1.getText().toString();
            age=t2.getText().toString();
            email=t3.getText().toString();

            try{
                db = this.openOrCreateDatabase( "student", MODE_PRIVATE, null );
                db.execSQL( "create table if not exists test(name varchar(20),age varchar(20),email varchar(50));" );

                if (view.getId()  == b1.getId()) {
                    db.execSQL( "insert into test values('"+name+"','"+age+"','"+email+"');" );
                    Toast.makeText( getApplicationContext(),"Row inserted successfully",Toast.LENGTH_SHORT ).show();
                }

                if(view.getId()==b2.getId()){
                    Cursor c=db.rawQuery( "select * from test",null );
                    String all="";

                    if(c!=null)
                    {
                        if(c.moveToFirst())
                        {
                            do{
                                name=c.getString( c.getColumnIndex( "name" ) );
                                age=c.getString( c.getColumnIndex( "age" ) );
                                email=c.getString( c.getColumnIndex( "email" ) );
                                all=all+name+"\t\t"+age+"\t\t"+email+"\n";

                            }while(c.moveToNext());
                            Toast.makeText( this,all,Toast.LENGTH_SHORT ).show();
                        }
                    }
                }
            }
            catch (SQLiteException sq)
            {
                Toast.makeText( getApplicationContext(),"Could not create or open database",Toast.LENGTH_SHORT ).show();
            }
            finally {
                if(db!=null)
                    db.close();
            }
    }
}
