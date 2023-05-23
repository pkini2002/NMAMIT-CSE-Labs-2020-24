public class MainActivity extends AppCompatActivity {
    String CHANNEL_1_ID="channel1";
    Button notify1;
    EditText message;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        notify1=findViewById(R.id.button);
        message=findViewById(R.id.editTextTextPersonName);
        notify1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String channelId="channel1";
                NotificationChannel channel1= null;
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                    channel1 = new NotificationChannel(CHANNEL_1_ID,"Channel1", NotificationManager.IMPORTANCE_HIGH);
                }
                NotificationManager nm=(NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                    nm.createNotificationChannel(channel1);
                }

                NotificationCompat.Builder mBuilder=new NotificationCompat.Builder(getApplicationContext(),CHANNEL_1_ID);

                mBuilder.setSmallIcon(R.drawable.ic_launcher_background);
                mBuilder.setContentTitle("Notification!");
                mBuilder.setContentText(message.getText().toString());
                mBuilder.setAutoCancel(true);

                Intent i = new Intent(getApplicationContext(), MainActivity2.class);
                i.putExtra("body", message.getText().toString());
                PendingIntent pi = PendingIntent.getActivity(getApplicationContext(), 0, i,
                        PendingIntent.FLAG_UPDATE_CURRENT | PendingIntent.FLAG_IMMUTABLE); // or use FLAG_MUTABLE if needed
                mBuilder.setContentIntent(pi);
                
                nm.notify(121,mBuilder.build());
            }
        });

    }
}
