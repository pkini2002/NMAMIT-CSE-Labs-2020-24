public class MainActivity2 extends AppCompatActivity {
    TextView message;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);

        message=findViewById(R.id.textView6);
        String mes=getIntent().getStringExtra("body");
        message.setText(mes);
    }
}
