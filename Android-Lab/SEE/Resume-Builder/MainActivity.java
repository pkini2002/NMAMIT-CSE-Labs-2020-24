import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import android.annotation.SuppressLint;
import android.content.Intent;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.RadioGroup;

public class MainActivity extends AppCompatActivity {
 EditText name, email, phone, qualif;
 Button Pic, submit;
 RadioGroup gender;
 RadioButton r;
 ImageView profilePic;
 public static Bitmap profilepic;
  
 @Override
 protected void onActivityResult(int requestCode, int resultCode, @NullableIntent data) {
     if(requestCode==1 && resultCode==RESULT_OK)
     {
         profilepic = (Bitmap)data.getExtras().get("data");
         profilePic.setImageBitmap(profilepic);
     }
     super.onActivityResult(requestCode, resultCode, data);
     }
  
     @SuppressLint("MissingInflatedId")
     @Override
     protected void onCreate(Bundle savedInstanceState) {
         super.onCreate(savedInstanceState);
         setContentView(R.layout.activity_main);
         name = findViewById(R.id.Name);
         email = findViewById(R.id.Email);
         phone = findViewById(R.id.Number);
         qualif = findViewById(R.id.Qualifications);
         Pic = findViewById(R.id.TakePic);
         submit = findViewById(R.id.Submit);
         gender = findViewById(R.id.Gender);
         profilePic = findViewById(R.id.ProfilePic);
         submit.setOnClickListener(new View.OnClickListener() {
         @Override
         public void onClick(View view) {
                 Intent i = new Intent(getApplicationContext(), ResumeView.class);
                 i.putExtra("name", name.getText().toString());
                 i.putExtra("Qualification", qualif.getText().toString());
                 i.putExtra("email", email.getText().toString());
                 i.putExtra("phone", phone.getText().toString());
                 int gid = gender.getCheckedRadioButtonId();
                 r=findViewById(gid);
                 String gstr = r.getText().toString();
                 i.putExtra("gender", gstr);
                 startActivity(i);
         }
         });
       
     Pic.setOnClickListener(new View.OnClickListener() {
     @Override
     public void onClick(View view) {
             Intent Pici=new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
             startActivityForResult(Pici,1);
     }
     });
 }
}
