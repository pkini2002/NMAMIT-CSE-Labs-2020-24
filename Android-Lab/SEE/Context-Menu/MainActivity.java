import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import android.annotation.SuppressLint;
import android.graphics.Color;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
 TextView cmenu;
 ConstraintLayout cl;
 @SuppressLint("MissingInflatedId")
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);
   
 cmenu = (TextView) findViewById(R.id.CMenu);
 cl = (ConstraintLayout) findViewById(R.id.CL);
 registerForContextMenu(cmenu);
 }
  
 public void onCreateContextMenu(ContextMenu menu, View V, ContextMenu.ContextMenuInfo menuInfo){
     MenuInflater m = getMenuInflater();
     m.inflate(R.menu.menu,menu);
    super.onCreateContextMenu(menu, V, menuInfo);
 }
  
 public boolean onContextItemSelected(MenuItem item) {
    int id = item.getItemId();
    if (id == R.id.red) {
        cl.setBackgroundColor(Color.RED);
        return true;
    } 
   else if (id == R.id.green) {
       cl.setBackgroundColor(Color.GREEN);
       return true;
    } 
   else if (id == R.id.blue) {
        cl.setBackgroundColor(Color.BLUE);
        return true;
   } 
   else {
      return super.onContextItemSelected(item);
 }
 }
}
