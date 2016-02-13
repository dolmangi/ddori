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
public class DdoriSensorListener extends AbstractNodeMain {
    private MessageCallable<String, ddori_msgs.ddori_sensor> callable;

    public DdoriSensorListener() {
    }
    @Override
    public GraphName getDefaultNodeName() {
        return GraphName.of("rosjava_tutorial_pubsub/ddori_sensor_listener");
    }
    @Override
    public void onStart(ConnectedNode connectedNode) {
        final Log log = connectedNode.getLog();
        Subscriber<ddori_msgs.ddori_sensor> subscriber = connectedNode.newSubscriber("ddori_sensor",  ddori_msgs.ddori_sensor._TYPE);
        subscriber.addMessageListener(new MessageListener <ddori_msgs.ddori_sensor>( )     {
            @Override
            public void onNewMessage(final ddori_msgs.ddori_sensor message) {
                String ret = "";
                if (callable != null) {
                    callable.call(message);
                } else {
                    android.util.Log.v("ROS Subscriber", "ddorisensor");
                }
            }
        });
    }


    public void setMessageToStringCallable(MessageCallable<String, ddori_msgs.ddori_sensor> callable) {
        this.callable = callable;
    }

    @Override
    public void onShutdown(Node node) {

    }

}