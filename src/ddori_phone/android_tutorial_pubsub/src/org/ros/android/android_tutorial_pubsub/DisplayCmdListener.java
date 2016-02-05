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
 * Created by seokwang on 2016-02-04.
 */
public class DisplayCmdListener extends AbstractNodeMain {
    private MessageCallable<String, ddori_msgs.display> callable;

    public DisplayCmdListener() {
    }
    @Override
    public GraphName getDefaultNodeName() {
        return GraphName.of("rosjava_tutorial_pubsub/ddori_display_command_listener");
    }
    @Override
    public void onStart(ConnectedNode connectedNode) {
        final Log log = connectedNode.getLog();
        Subscriber<ddori_msgs.display> subscriber = connectedNode.newSubscriber("ddori_display_cmd",  ddori_msgs.display._TYPE);
        subscriber.addMessageListener(new MessageListener<ddori_msgs.display>( )     {
            @Override
            public void onNewMessage(final ddori_msgs.display message) {
                String ret = "";
                if (callable != null) {
                    callable.call(message);
                } else {
                    android.util.Log.v("ROS Subscriber", "ddori_msgs.display");
                }
            }
        });
    }


    public void setMessageToStringCallable(MessageCallable<String, ddori_msgs.display> callable) {
        this.callable = callable;
    }

    @Override
    public void onShutdown(Node node) {

    }

}