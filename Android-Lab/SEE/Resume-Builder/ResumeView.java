import androidx.appcompat.app.AppCompatActivity;
import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

public class ResumeView extends AppCompatActivity {
     ImageView profilePic;
     TextView name, qualification, email, phone, gender;
  
     @Override
     protected void onCreate(Bundle savedInstanceState) {
             super.onCreate(savedInstanceState);
             setContentView(R.layout.activity_resume_view);
             name = findViewById(R.id.UsrName);
             gender = findViewById(R.id.UsrGender);
             qualification = findViewById(R.id.UsrQualification);
             email = findViewById(R.id.UsrEmail);
             phone = findViewById(R.id.UsrNumber);
             profilePic = findViewById(R.id.UsrProfilePic);
             Intent i = getIntent();
             name.setText(i.getStringExtra("name"));
             gender.setText(i.getStringExtra("gender"));
             email.setText(i.getStringExtra("email"));
             phone.setText(i.getStringExtra("phone"));
             qualification.setText(i.getStringExtra("Qualification"));
             if (MainActivity.profilepic != null) {
             profilePic.setImageBitmap(MainActivity.profilepic);
             }
     }
}
