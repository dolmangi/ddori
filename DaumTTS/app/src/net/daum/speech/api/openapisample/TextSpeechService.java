package net.daum.speech.api.openapisample;

import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

import net.daum.mf.speech.api.TextToSpeechClient;
import net.daum.mf.speech.api.TextToSpeechListener;
import net.daum.mf.speech.api.TextToSpeechManager;
import net.daum.speech.api.openapisample.ITtsService;
/**
 * Created by seokwang on 2016-02-06.
 */
public class TextSpeechService extends Service implements TextToSpeechListener {
    private static final String TAG = "TextToSpeechActivity";

    private TextToSpeechClient ttsClient;

    public class TtsServiceImple extends ITtsService.Stub {

        @Override
        public void SetTts(String ttstext) throws RemoteException {
            Log.e(TAG, "TTS: " + ttstext + " 출력 준비");

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
                        .setListener(TextSpeechService.this)
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
        Log.e(TAG, "TTS: onBind 호출됨");

        return new TtsServiceImple();
    }

    @Override
    public void onCreate( ) {
        super.onCreate();
        Context ctx=getApplicationContext();
        TextToSpeechManager.getInstance().initializeLibrary(ctx);
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

        Log.i(TAG, "TTS: "+statusMessage);

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

        Log.i(TAG, "TTS: "+strInacctiveText);
            ttsClient = null;
    }


    @Override
    public void onDestroy() {
        super.onDestroy();
        ttsClient = null;
        Log.e(TAG, "TTS: onDestroy 호출됨");
    }

}
