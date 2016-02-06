package net.daum.speech.api.openapisample;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

import com.ddori.TTS.service.ITtsService;

import net.daum.mf.speech.api.TextToSpeechClient;
import net.daum.mf.speech.api.TextToSpeechListener;
import net.daum.mf.speech.api.TextToSpeechManager;

public class TextToSpeechActivity extends Service implements TextToSpeechListener {
    private static final String TAG = "TextToSpeechActivity";

    private TextToSpeechClient ttsClient;

//    private TextView mStatus;
//    private Spinner mSpinnerMode;
    public class TtsServiceImple extends ITtsService.Stub {

        @Override
         public void SetTts(String ttstext) throws RemoteException {
            Log.e(TAG, "TTS: " + ttstext + " 출력 준비");
            //speak(ttstext);

            if (ttsClient != null && ttsClient.isPlaying()) {
                Log.e(TAG, "TTS: previous voice is not finished");
//                ttsClient.stop();
            }
            if (ttsClient == null) {
                ttsClient = new TextToSpeechClient.Builder()
                        .setApiKey(SpeechSampleActivity.APIKEY)
                        .setSpeechMode(TextToSpeechClient.NEWTONE_TALK_2)
                        .setSpeechSpeed(1.0)
                        .setSpeechVoice(TextToSpeechClient.VOICE_WOMAN_DIALOG_BRIGHT)
                        .setListener(TextToSpeechActivity.this)
                        .build();

                SendTts(ttstext);
            }
            else {
                Log.e(TAG, "TTS: ttsClient is not null");
            }

            return;
        }
    }

    public void SendTts(String txt)
    {
        if (ttsClient != null && ttsClient.play(txt)) {
            Log.e(TAG, "TTS: " + txt + " 출력 완료");
        }
    }

    @Override
    public IBinder onBind(Intent p_intent) {
        Log.e(TAG, "onBind 호출됨");
        SendTts("hello ddori");
        return new TtsServiceImple();
    }

    @Override
    public void onCreate( ) {
        super.onCreate();
//        setContentView(R.layout.activity_tts);

        TextToSpeechManager.getInstance().initializeLibrary(getApplicationContext());

//        mStatus = (TextView) findViewById(R.id.textViewStatus);

//        mSpinnerMode = (Spinner)findViewById(R.id.spinnerMode);

        //       ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this, R.array.mode, android.R.layout.simple_spinner_item);
//        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        //       mSpinnerMode.setAdapter(adapter);

//        ImageButton buttonStartStop = (ImageButton) findViewById(R.id.imageButtonStart);
        /*
        buttonStartStop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (ttsClient != null && ttsClient.isPlaying()) {
                    ttsClient.stop();
                    return;
                }
*/
//                EditText editText1 = (EditText) findViewById(R.id.editTextTTS);
        //               String strText = editText1.getText().toString();
/*
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
            }
        });
        */



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
        /*
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                mStatus.setText(statusMessage);
            }
        });
        */
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
        /*
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                mStatus.setText(strInacctiveText);
            }
        });
        */

        ttsClient = null;
    }


    @Override
    public void onDestroy() {
        super.onDestroy();
        ttsClient = null;


        Log.e(TAG, "onDestroy 호출됨");
    }

}
