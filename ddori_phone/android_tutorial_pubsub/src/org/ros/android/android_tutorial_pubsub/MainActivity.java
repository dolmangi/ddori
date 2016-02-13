/*
 * Copyright (C) 2011 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

package org.ros.android.android_tutorial_pubsub;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.widget.ImageView;
import android.widget.Toast;


import net.daum.speech.api.openapisample.ITtsService;

import org.ros.android.MessageCallable;
import org.ros.android.RosActivity;
import org.ros.android.view.RosTextView;
import org.ros.node.NodeConfiguration;
import org.ros.node.NodeMainExecutor;
import org.ros.rosjava_tutorial_pubsub.Talker;

import java.net.URI;
import java.util.ArrayList;


/**
 * @author damonkohler@google.com (Damon Kohler)
 */
public class MainActivity extends RosActivity {

  private RosTextView<std_msgs.String> rosTextView;
  private RosTextView<std_msgs.String> rosListener;
  private Talker talker;
  private TTSCmdListener listener;
  private DdoriSensorListener ddori_sensor;
  private DisplayCmdListener disp_cmd;
  private static final java.lang.String TAG = "DDORI_UI";
  private ITtsService mTTSService = null;
   private  ImageView ddori_face;

  public MainActivity() {
    // The RosActivity constructor configures the notification title and ticker
    // messages.
    super("Pubsub Tutorial", "Pubsub Tutorial", URI.create("http://dolmangi.iptime.org:11311"));
  }

  @SuppressWarnings("unchecked")
  @Override
  public void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.main);



    //ddori_face.setImageResource(R.drawable.happy);


    String tts_class_name =  ITtsService.class.getName(); //"net.daum.speech.api.openapisample.ITtsService" ;//
    bindService(new Intent(tts_class_name), mSerConn1, Context.BIND_AUTO_CREATE);



    rosTextView = (RosTextView<std_msgs.String>) findViewById(R.id.text);
    rosTextView.setTopicName("chatter");
    rosTextView.setMessageType(std_msgs.String._TYPE);
    rosTextView.setMessageToStringCallable(new MessageCallable<String, std_msgs.String>() {
        @Override
        public String call(std_msgs.String message) {
            return message.getData();
        }
    });

     // face_change();
    /*
    rosListener = (RosTextView<std_msgs.String>) findViewById(R.id.listener);
    rosListener.setTopicName("dolchatter");
    rosListener.setMessageType(std_msgs.String._TYPE);
    rosListener.setMessageToStringCallable(new MessageCallable<String, std_msgs.String>() {
      @Override
      public String call(std_msgs.String message) {
        Log.e("Listener", "received a message [" + message.getData() + "]");
        return message.getData();
      }
    });
*/

  }
private void face_change()
{
    ArrayList<Integer> idle_face_list = new ArrayList<Integer>() {{
        add(R.drawable.kwi1);
        add(R.drawable.kwi2);
        add(R.drawable.kwi3);
        add(R.drawable.kwi4);
        add(R.drawable.kwi5);
        add(R.drawable.kwi6);
        add(R.drawable.kwi7);
        add(R.drawable.kwi8);
        add(R.drawable.kwi9);
        add(R.drawable.kwi10);
        add(R.drawable.kwi11);
    }};
    int img_num =  (int) (Math.random()*10+1);
    int img_id=idle_face_list.get(img_num);
    ddori_face.setImageResource(img_id);
}
  @Override
  protected void init(NodeMainExecutor nodeMainExecutor) {
    talker = new Talker();
    // At this point, the user has already been prompted to either enter the URI
    // of a master to use or to start a master locally.

    // The user can easily use the selected ROS Hostname in the master chooser
    // activity.
    NodeConfiguration nodeConfiguration = NodeConfiguration.newPublic(getRosHostname());
    nodeConfiguration.setMasterUri(getMasterUri());

      /*
    nodeMainExecutor.execute(talker, nodeConfiguration);
    // The RosTextView is also a NodeMain that must be executed in order to
    // start displaying incoming messages.
    nodeMainExecutor.execute(rosTextView, nodeConfiguration);
*/
    listener = new TTSCmdListener();
      listener.setMessageToStringCallable(new MessageCallable<String, String>() {
          @Override
          public String call(String message) {
              callServiceTTS(message);
            return message;
        }
    });
    nodeMainExecutor.execute(listener, nodeConfiguration);



      ddori_sensor = new DdoriSensorListener();
      ddori_sensor.setMessageToStringCallable(new MessageCallable<String, ddori_msgs.ddori_sensor>() {
          @Override
          public String call(final ddori_msgs.ddori_sensor message) {
              android.util.Log.v(TAG, "ddori_sensor" + String.valueOf(message.getTimeStamp()));
              return "";
          }
      });
      nodeMainExecutor.execute(ddori_sensor, nodeConfiguration);




      disp_cmd= new DisplayCmdListener();
      disp_cmd.setMessageToStringCallable(new MessageCallable<String, ddori_msgs.display>() {
          @Override
          public String call(final ddori_msgs.display message) {
              android.util.Log.v(TAG, "ddori_msgs.display:" + message.getCommand());
              String cmd = message.getCommand();
              if (cmd.equals("face_change")) {
                  String ddori_state = message.getArg1();
                  if (ddori_state.equals("idle")) {

                  }
              }
              return "";
          }
      });
      nodeMainExecutor.execute(disp_cmd, nodeConfiguration);

    //  callServiceTTS("안녕하세요?");

      /*
    try {
      // Really horrible hack till I work out exactly the root cause and fix for
      // https://github.com/rosjava/android_remocons/issues/47
      Thread.sleep(1000);
      java.net.Socket socket = new java.net.Socket(getMasterUri().getHost(), getMasterUri().getPort());
      java.net.InetAddress local_network_address = socket.getLocalAddress();
      socket.close();

      NodeConfiguration nodeListenerConfiguration =  NodeConfiguration.newPublic(local_network_address.getHostAddress(), getMasterUri());
      nodeMainExecutor.execute(listener, nodeListenerConfiguration);
      //nodeMainExecutor.execute(rosListener, nodeListenerConfiguration);

    } catch(InterruptedException e) {
      // Thread interruption
      Log.e("Listener", "Thread interruption.........................................");
    } catch (IOException e) {
      // Socket problem
      Log.e("Listener", "Socket problem.........................................");
    }
    */
  }
  @Override
  protected void onDestroy() {
   //   callServiceTTS("안녕히 계세요");
    unbindService(mSerConn1);
    super.onDestroy();
  }


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
        if (mTTSService != null) {
            mTTSService.SetTts(txt);
        }
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Toast.makeText(MainActivity.this, txt, Toast.LENGTH_SHORT).show();
            }
        });

    } catch(RemoteException e) {
      android.util.Log.e(TAG, e.getMessage(), e);
    }
  }

}
