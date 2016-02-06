package net.daum.speech.api.openapisample;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.TextView;

import net.daum.mf.speech.api.TextToSpeechClient;
import net.daum.mf.speech.api.TextToSpeechListener;
import net.daum.mf.speech.api.TextToSpeechManager;

public class TextToSpeechActivity extends Activity implements TextToSpeechListener {
    private static final String TAG = "TextToSpeechActivity";

    private TextToSpeechClient ttsClient;

    private TextView mStatus;
    private Spinner mSpinnerMode;



    private ITtsService mTTSService = null;

    private ServiceConnection mSerConn1 = new ServiceConnection() {

        @Override
        public void onServiceDisconnected(ComponentName p_name) {
            android.util.Log.v(TAG, "onServiceDisconnected 호출됨");
            mTTSService = null;
        }

        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            android.util.Log.v(TAG, "onServiceConnected 호출됨");
            mTTSService = ITtsService.Stub.asInterface(service);
//            callServiceTTS();
        }
    };

    public void callServiceTTS(final java.lang.String txt) {
        try {
            mTTSService.SetTts(txt);
//            Toast.makeText(this, "서비스 TTS 에 보냅니다", Toast.LENGTH_SHORT).show();
        } catch(RemoteException e) {
            android.util.Log.e(TAG, e.getMessage(), e);
        }
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tts);
/*
        Context ctx=getApplicationContext();
        TextToSpeechManager.getInstance().initializeLibrary(ctx);

        mStatus = (TextView) findViewById(R.id.textViewStatus);


        mSpinnerMode = (Spinner)findViewById(R.id.spinnerMode);

        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this, R.array.mode, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        mSpinnerMode.setAdapter(adapter);
*/

        String tts_class_name = ITtsService.class.getName();
        bindService(new Intent(tts_class_name), mSerConn1, Context.BIND_AUTO_CREATE);

        ImageButton buttonStartStop = (ImageButton) findViewById(R.id.imageButtonStart);
        buttonStartStop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
/*                if (ttsClient != null && ttsClient.isPlaying()) {
                    ttsClient.stop();
*/
                    callServiceTTS("안녕하세요?");
                    return;
                }

                /*
                EditText editText1 = (EditText) findViewById(R.id.editTextTTS);
                String strText = editText1.getText().toString();

                String speechMode;
                String voiceType;
                double speechSpeed = 1.0;

                switch(mSpinnerMode.getSelectedItemPosition()) {
                    case 1:
                        speechMode = TextToSpeechClient.NEWTONE_TALK_2;
                        break;
                    case 0:
                    default:
                        speechMode = TextToSpeechClient.NEWTONE_TALK_1;
                        break;
                }

                RadioGroup radioVoice = (RadioGroup)findViewById(R.id.voiceRadioGroup);
                RadioGroup radioSpeed = (RadioGroup)findViewById(R.id.speedRadioGroup);

                switch(radioVoice.getCheckedRadioButtonId()) {
                    case R.id.voiceManReadCalm:
                        voiceType = TextToSpeechClient.VOICE_MAN_READ_CALM;
                        break;
                    case R.id.voiceWomanReadCalm:
                        voiceType = TextToSpeechClient.VOICE_WOMAN_READ_CALM;
                        break;
                    case R.id.voiceManDialogBright:
                        voiceType = TextToSpeechClient.VOICE_MAN_DIALOG_BRIGHT;
                        break;
                    case R.id.voiceWomanDialogBright:
                    default:
                        voiceType = TextToSpeechClient.VOICE_WOMAN_DIALOG_BRIGHT;
                        break;
                }
                if (radioSpeed.getCheckedRadioButtonId() == R.id.speed05x) {
                    speechSpeed = 0.5;
                }
                else if (radioSpeed.getCheckedRadioButtonId() == R.id.speed20x) {
                    speechSpeed = 2.0;
                }

                ttsClient = new TextToSpeechClient.Builder()
                        .setApiKey(SpeechSampleActivity.APIKEY)
                        .setSpeechMode(speechMode)
                        .setSpeechSpeed(speechSpeed)
                        .setSpeechVoice(voiceType)
                        .setListener(TextToSpeechActivity.this)
                        .build();

                if (ttsClient.play(strText)) {
                    mStatus.setText("playTTS");
                }
            }        */
        });

    }

    private void handleError(int errorCode) {
        String errorText;
        switch (errorCode) {
            case TextToSpeechClient.ERROR_NETWORK:
                errorText = "네트워크 오류";
                break;
            case TextToSpeechClient.ERROR_NETWORK_TIMEOUT:
                errorText = "네트워크 지연";
                break;
            case TextToSpeechClient.ERROR_CLIENT_INETRNAL:
                errorText = "음성합성 클라이언트 내부 오류";
                break;
            case TextToSpeechClient.ERROR_SERVER_INTERNAL:
                errorText = "음성합성 서버 내부 오류";
                break;
            case TextToSpeechClient.ERROR_SERVER_TIMEOUT:
                errorText = "음성합성 서버 최대 접속시간 초과";
                break;
            case TextToSpeechClient.ERROR_SERVER_AUTHENTICATION:
                errorText = "음성합성 인증 실패";
                break;
            case TextToSpeechClient.ERROR_SERVER_SPEECH_TEXT_BAD:
                errorText = "음성합성 텍스트 오류";
                break;
            case TextToSpeechClient.ERROR_SERVER_SPEECH_TEXT_EXCESS:
                errorText = "음성합성 텍스트 허용 길이 초과";
                break;
            case TextToSpeechClient.ERROR_SERVER_UNSUPPORTED_SERVICE:
                errorText = "음성합성 서비스 모드 오류";
                break;
            case TextToSpeechClient.ERROR_SERVER_ALLOWED_REQUESTS_EXCESS:
                errorText = "허용 횟수 초과";
                break;
            default:
                errorText = "정의하지 않은 오류";
                break;
        }

        final String statusMessage = errorText + " (" + errorCode + ")";

        Log.i(TAG, statusMessage);
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                mStatus.setText(statusMessage);
            }
        });
    }

    @Override
    public void onError(int code, String message) {
        handleError(code);

        ttsClient = null;
    }

    @Override
    public void onFinished() {
        int intSentSize = ttsClient.getSentDataSize();
        int intRecvSize = ttsClient.getReceivedDataSize();

        final String strInacctiveText = "onFinished() SentSize : " + intSentSize + " RecvSize : " + intRecvSize;

        Log.i(TAG, strInacctiveText);
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                mStatus.setText(strInacctiveText);
            }
        });

        ttsClient = null;
    }


    @Override
    protected void onDestroy() {
     ///   callServiceTTS("안녕히 계세요");
        unbindService(mSerConn1);
        super.onDestroy();
    }
}
