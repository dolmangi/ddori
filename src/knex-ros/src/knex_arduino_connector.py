#!/usr/bin/env python
import roslib; roslib.load_manifest('knex_ros')
import rospy
from std_msgs.msg import String
from std_msgs.msg import Int16
from std_msgs.msg import Float32
import wx


######################################################################
######################################################################
class MainWindow(wx.Frame):
    """ the main window """
    
    ######################################################################
    def set_status_text(self, txt):
    ######################################################################
        wx.CallAfter(self.tbArduinoDebug.SetValue, txt)

    ######################################################################
    def arduino_debug_callback(self, data):
    ######################################################################
        self.set_status_text(data.data)
        
    ######################################################################
    def __init__(self, parent, title):
    ######################################################################
        wx.Frame.__init__(self, parent, title=title, size=(300,600))
        panel = wx.Panel(self, -1)
        self.top_sizer = wx.BoxSizer(wx.VERTICAL)
        
        self.tbArduinoDebug = wx.TextCtrl(panel)
        self.lblDebug = wx.StaticText(panel, -1, "debug", (150,50))

        self.row1_sizer = wx.BoxSizer(wx.HORIZONTAL)
        self.row1_sizer.Add(self.lblDebug)
        self.row1_sizer.Add(self.tbArduinoDebug)
        
        
        
        self.lblSliderL = wx.StaticText(panel, -1, "Left", (25,50), style=wx.ALIGN_RIGHT)
        self.sldLeft = wx.Slider(panel, -1, 0, -255, 255, wx.DefaultPosition, (250, 50),
                             wx.SL_AUTOTICKS | wx.SL_HORIZONTAL | wx.SL_LABELS)
        
        self.row2_sizer = wx.BoxSizer(wx.HORIZONTAL)
        self.row2_sizer.Add(self.lblSliderL)
        self.row2_sizer.Add(self.sldLeft)
        
        self.lblSliderR = wx.StaticText(panel, -1, "Right", (25,50), style=wx.ALIGN_RIGHT | wx.ALIGN_CENTER_VERTICAL)
        self.sldRight = wx.Slider(panel, -1, 0, -255, 255, wx.DefaultPosition, (250,50),
                                  wx.SL_AUTOTICKS | wx.SL_HORIZONTAL | wx.SL_LABELS)
        self.sldLeft.Bind(wx.EVT_SLIDER,self.OnSliderLeft)
        self.sldRight.Bind(wx.EVT_SLIDER,self.OnSliderRight)
        
        self.row3_sizer=wx.BoxSizer(wx.HORIZONTAL)
        self.row3_sizer.Add(self.lblSliderR)
        self.row3_sizer.Add(self.sldRight)
        
        self.btnZero = wx.Button(panel, -1, "Zero", (25,50))
        self.btnZero.Bind(wx.EVT_BUTTON, self.OnButtonZero)
        
        self.row4_sizer = wx.BoxSizer( wx.HORIZONTAL )
        self.row4_sizer.Add( self.btnZero )
        
        self.lblSliderServo1 = wx.StaticText(panel, -1, "Servos:", style=wx.ALIGN_CENTER| wx.ALIGN_CENTER_VERTICAL)
        
        self.row5_sizer = wx.BoxSizer( wx.HORIZONTAL )
        self.row5_sizer.Add(self.lblSliderServo1)
        
        self.sldServo1 = wx.Slider(panel, -1, 0, 0, 179, wx.DefaultPosition, (250, 50), wx.SL_AUTOTICKS | wx.SL_HORIZONTAL | wx.SL_LABELS)
        self.sldServo2 = wx.Slider(panel, -1, 0, 0, 179, wx.DefaultPosition, (250, 50), wx.SL_AUTOTICKS | wx.SL_HORIZONTAL | wx.SL_LABELS)
        self.sldServo3 = wx.Slider(panel, -1, 0, 0, 179, wx.DefaultPosition, (250, 50), wx.SL_AUTOTICKS | wx.SL_HORIZONTAL | wx.SL_LABELS)
        self.sldServo4 = wx.Slider(panel, -1, 0, 0, 179, wx.DefaultPosition, (250, 50), wx.SL_AUTOTICKS | wx.SL_HORIZONTAL | wx.SL_LABELS)
        self.sldServo5 = wx.Slider(panel, -1, 0, 0, 179, wx.DefaultPosition, (250, 50), wx.SL_AUTOTICKS | wx.SL_HORIZONTAL | wx.SL_LABELS)
        
        self.sldServo1.Bind(wx.EVT_SLIDER, self.OnSliderServo1)
        self.sldServo2.Bind(wx.EVT_SLIDER, self.OnSliderServo2)
        self.sldServo3.Bind(wx.EVT_SLIDER, self.OnSliderServo3)
        self.sldServo4.Bind(wx.EVT_SLIDER, self.OnSliderServo4)
        self.sldServo5.Bind(wx.EVT_SLIDER, self.OnSliderServo5)
        self.row6_sizer = wx.BoxSizer( wx.VERTICAL )
        
        self.row6_sizer.Add(self.sldServo1)
        self.row6_sizer.Add(self.sldServo2)
        self.row6_sizer.Add(self.sldServo3)
        self.row6_sizer.Add(self.sldServo4)
        self.row6_sizer.Add(self.sldServo5)
       
        self.lblSpeed = wx.StaticText(panel, -1, "Speed:", style=wx.ALIGN_CENTER| wx.ALIGN_CENTER_VERTICAL)
        self.sldSpeed = wx.Slider(panel, -1, 0, -50, 50, wx.DefaultPosition, (250, 50), wx.SL_AUTOTICKS | wx.SL_HORIZONTAL | wx.SL_LABELS)
        self.lblAngle = wx.StaticText(panel, -1, "Angle:", style=wx.ALIGN_CENTER| wx.ALIGN_CENTER_VERTICAL)
        self.sldAngle = wx.Slider(panel, -1, 0, -100, 100, wx.DefaultPosition, (250, 50), wx.SL_AUTOTICKS | wx.SL_HORIZONTAL | wx.SL_LABELS)
        self.sldSpeed.Bind(wx.EVT_SLIDER, self.OnSliderSpeed)
        self.sldSpeed.Bind(wx.EVT_LEFT_UP, self.OnSliderUp)
        self.row7_sizer = wx.BoxSizer( wx.VERTICAL )
        
        self.row7_sizer.Add(self.lblSpeed)
        self.row7_sizer.Add(self.sldSpeed)
        self.row7_sizer.Add(self.lblAngle)
        self.row7_sizer.Add(self.sldAngle)
        
        
        self.top_sizer.Add(self.row1_sizer)
        self.top_sizer.Add(self.row2_sizer)
        self.top_sizer.Add(self.row3_sizer)
        self.top_sizer.Add(self.row4_sizer)
        self.top_sizer.Add(self.row5_sizer)
        self.top_sizer.Add(self.row6_sizer)
        self.top_sizer.Add(self.row7_sizer)
        
        panel.SetSizer(self.top_sizer)
                
        pub = rospy.Publisher('chatter', String, queue_size=10)
        self.pub_lmotor = rospy.Publisher('lmotor_cmd', Float32, queue_size=10)
        self.pub_rmotor = rospy.Publisher('rmotor_cmd', Float32, queue_size=10)
        self.pub_servo1 = rospy.Publisher('servo1_cmd', Int16, queue_size=10)
        self.pub_servo2 = rospy.Publisher('servo2_cmd', Int16, queue_size=10)
        self.pub_servo3 = rospy.Publisher('servo3_cmd', Int16, queue_size=10)
        self.pub_servo4 = rospy.Publisher('servo4_cmd', Int16, queue_size=10)
        self.pub_servo5 = rospy.Publisher('servo5_cmd', Int16, queue_size=10)
        self.pub_lwheel_vtarget = rospy.Publisher('lwheel_vtarget', Float32, queue_size=10)
        self.pub_rwheel_vtarget = rospy.Publisher('rwheel_vtarget', Float32, queue_size=10)
        rospy.init_node('knex_arduino_connector')
        rospy.Subscriber("arduino_debug", String, self.arduino_debug_callback)    
        TIMER_ID = 200 
        self.timer = wx.Timer(self, TIMER_ID) 
        self.Bind(wx.EVT_TIMER, self.OnTimer, self.timer)
        SPEED_TIMER_ID = 201
        self.speed_timer = wx.Timer(self, SPEED_TIMER_ID) 
        self.Bind(wx.EVT_TIMER, self.OnSpeedTimer, self.speed_timer)
        self.ds1 = 0
        self.ds2 = 0
        
        self.joy = wx.Joystick(1)
        self.joy.SetCapture(self)
        self.Bind(wx.EVT_JOY_BUTTON_DOWN, self.OnJoyBtnDown)
        self.Bind(wx.EVT_JOY_BUTTON_UP, self.OnJoyBtnUp)
        self.Bind(wx.EVT_JOY_MOVE, self.OnJoyMove)
        rospy.loginfo ( "done initializing") 
        
    ######################################################################
    def OnJoyBtnUp(self, event):
    ######################################################################
        self.ds1 = 0
        self.ds2 = 0
        self.timer.Stop()
        
    ######################################################################
    def OnJoyBtnDown(self, event):
    ######################################################################
        btn = event.GetButtonChange()
        # rospy.loginfo( "Joystick button %d pressed" % btn ) 
        stepsize=5
        
        if (btn == 7):
            self.ds1 = stepsize
        if (btn == 9):
            self.ds1 = 0 - stepsize
        if (btn == 8):
            self.ds2 = stepsize
        if (btn == 6):
            self.ds2 =  0 - stepsize
        self.timer.Start(25) 
        
    ######################################################################
    def OnTimer(self, event):
    ######################################################################
        s1 = self.sldServo1.GetValue()
        s2 = self.sldServo2.GetValue()
        s1 = s1 + self.ds1
        s2 = s2 + self.ds2
        # rospy.loginfo("ontimer %d %d %d %d" %(s1,s2,self.ds1, self.ds2))
        wx.CallAfter( self.sldServo1.SetValue, s1)
        wx.CallAfter( self.sldServo2.SetValue, s2)
        self.pub_servo1.publish( self.sldServo1.GetValue())
        self.pub_servo2.publish( self.sldServo2.GetValue())
        
    ######################################################################
    def OnJoyMove(self, event):
    ######################################################################
        pos = self.joy.GetPosition()
        max = self.joy.GetXMax()
        # rospy.loginfo( "Joystick move x=%d, y=%d max=%d" % (pos[0], pos[1], max) )
        self.diff_drive(float(-pos[0]) / max, float(pos[1]) / max)
        
        
    ######################################################################
    def diff_drive(self, x, y):
    ######################################################################
        # rospy.loginfo("diffdrive x=%0.3f, y=%0.3f" % (x,y))
        threshold = 0.1
        if ( abs(x) < threshold and abs(y) < threshold ):
            l = 0
            r = 0
            
        else:
            if( x >= 0):
                rmin = x - 1  # -1 to 0
                rmax = 1
                lmin = -1
                lmax = 1 - x  # 1 to 0
            else:
                rmin = -1
                rmax = 1 + x  # 1 to 0
                lmin = -1 - x # -1 to 0
                lmax = 1
        
            l = lmin + ( lmax - lmin ) / 2 + y * (lmax - lmin) / 2 * -1
            r = rmin + ( rmax - rmin ) / 2 + y * (rmax - rmin) / 2 * -1
            rospy.loginfo( " l:%0.2f(%0.2f:%0.2f) r:%0.2f(%0.2f:%0.2f)" % (l,lmin,lmax,r,rmin,rmax))
        
        wx.CallAfter( self.sldLeft.SetValue, l * 255)
        wx.CallAfter( self.sldRight.SetValue, r * 255)
        self.pub_lmotor.publish( l * -255 )
        self.pub_rmotor.publish( r * -255)
        
    ######################################################################
    def OnSliderLeft(self, evt):
    ######################################################################
        rospy.loginfo ( "Left slider value %d" % self.sldLeft.GetValue() )
        wx.CallAfter(self.pub_lmotor.publish, self.sldLeft.GetValue())
        
    ######################################################################
    def OnSliderRight(self, evt):
    ######################################################################
        rospy.loginfo ( "Right slider value %d" % self.sldRight.GetValue() )
        wx.CallAfter(self.pub_rmotor.publish, self.sldRight.GetValue())
        
    ######################################################################
    def OnButtonZero(self, evt):
    ######################################################################
        rospy.loginfo("Button Zero")
        wx.CallAfter( self.sldLeft.SetValue, 0)
        wx.CallAfter( self.sldRight.SetValue, 0)
        self.pub_rmotor.publish(0)
        self.pub_lmotor.publish(0)
        
        
    ######################################################################
    def OnSliderServo1(self, evt):
    ######################################################################
        rospy.loginfo("Servo1 slider value %d" % self.sldServo1.GetValue())
        self.pub_servo1.publish( self.sldServo1.GetValue())
        
    ######################################################################
    def OnSliderServo2(self, evt):
    ######################################################################
        rospy.loginfo("Servo2 slider value %d" % self.sldServo2.GetValue())
        self.pub_servo2.publish( self.sldServo2.GetValue())
        
    ######################################################################
    def OnSliderServo3(self, evt):
    ######################################################################
        rospy.loginfo("Servo3 slider value %d" % self.sldServo3.GetValue())
        self.pub_servo3.publish( self.sldServo3.GetValue())
        
    ######################################################################
    def OnSliderServo4(self, evt):
    ######################################################################
        rospy.loginfo("Servo4 slider value %d" % self.sldServo4.GetValue())
        self.pub_servo4.publish( self.sldServo4.GetValue())
        
    ######################################################################
    def OnSliderServo5(self, evt):
    ######################################################################
        rospy.loginfo("Servo5 slider value %d" % self.sldServo5.GetValue())
        self.pub_servo5.publish( self.sldServo5.GetValue())
        
    ######################################################################
    def OnSliderSpeed(self, evt):
    ######################################################################
        # rospy.loginfo("OnSliderSpeed")
        self.speed = self.sldSpeed.GetValue()
        if abs(self.speed) < 2:
            self.speed_timer.Stop()
        else:
            self.speed_timer.Start(25)
        
    ######################################################################
    def OnSpeedTimer(self, event):
    ######################################################################
        angle = self.sldAngle.GetValue()
        speed = self.sldSpeed.GetValue()
        rspeed = -1.0 * (1.0 - angle / 100.0) * speed
        lspeed = -1.0 * (1.0 + angle / 100.0) * speed
        if abs(lspeed) > 2:
            self.pub_lwheel_vtarget.publish(lspeed)
        if abs(rspeed) > 2:
            self.pub_rwheel_vtarget.publish(rspeed)
        
    ######################################################################
    def OnSliderUp(self, event):
    ######################################################################
        self.speed_timer.Stop()
        self.pub_lwheel_vtarget.publish(0)
        self.pub_rwheel_vtarget.publish(0)
        wx.CallAfter( self.sldSpeed.SetValue, 0)
        event.Skip()
        
        


######################################################################
def launch_window():
######################################################################
    """ launches the GUI and nothing else """
        
    app = wx.App(False)  # Create a new app, don't redirect stdout/stderr to a window.
    frame = MainWindow(None, "Kinex arduino connector") # A Frame is a top-level window.
    frame.Show(True)     # Show the frame. 
    app.MainLoop()
        
        
        
######################################################################
######################################################################
if __name__ == '__main__':
    try:
        launch_window()
    except rospy.ROSInterruptException: pass