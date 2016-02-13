package org.ros.android.android_tutorial_pubsub;


import org.apache.commons.logging.Log;

import org.ros.android.MessageCallable;
import org.ros.message.MessageListener;
import org.ros.namespace.GraphName;
import org.ros.node.AbstractNodeMain;
import org.ros.node.ConnectedNode;
import org.ros.node.Node;
import org.ros.node.topic.Subscriber;
import java.lang.String;

/**
 * Created by seokwang on 2016-02-03.
 */

public class TTSCmdListener extends AbstractNodeMain {
    private MessageCallable<String, String> callable;

    public TTSCmdListener() {
    }
    @Override
    public GraphName getDefaultNodeName() {
        return GraphName.of("rosjava_tutorial_pubsub/dollistener");
    }
    @Override
    public void onStart(ConnectedNode connectedNode) {
        final Log log = connectedNode.getLog();
        Subscriber<std_msgs.String> subscriber = connectedNode.newSubscriber("dolchatter",  std_msgs.String._TYPE);
        subscriber.addMessageListener(new MessageListener<  std_msgs.String> ( )     {
            @Override
            public void onNewMessage(final std_msgs.String message)
            {
                if (callable != null) {
                    callable.call(message.getData() );
                  } else
                  {
                      android.util.Log.v("ROS Subscriber", "I heard: \"" + message.getData() + "\"");
                  }
            }
        });
    }


    public void setMessageToStringCallable(MessageCallable<String, String> callable) {
        this.callable = callable;
    }

    @Override
    public void onShutdown(Node node) {

    }

}
