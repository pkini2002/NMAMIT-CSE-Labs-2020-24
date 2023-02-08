// Generating random background colors on button click

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.util.Random;


public class MainActivity extends AppCompatActivity {
    Button click;
    ConstraintLayout lay;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Connecting the frontend components with the backend using their id's
        click=findViewById(R.id.button);
        lay=findViewById(R.id.constLayout);

        click.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Random r=new Random();
                int color= Color.rgb(r.nextInt(255),r.nextInt(255),r.nextInt(255));
                lay.setBackgroundColor(color);
            }
        });
    }
}
