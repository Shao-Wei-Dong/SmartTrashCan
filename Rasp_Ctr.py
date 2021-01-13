import time 
import RPi.GPIO as GPIO
import string
from email.mime.text import MIMEText
import smtplib
from socketserver import BaseRequestHandler, UDPServer

class TimeHandler(BaseRequestHandler):
    def handle(self):
        print('open', self.client_address)
        # Get message and client socket
        msg = 0
        msg, sock = self.request
        str(msg)
        print(msg)
        resp = time.ctime()
        sock.sendto(resp.encode('ascii'), self.client_address)
        
        cnt = 0
        GPIO.setwarnings(False)
        GPIO.setmode(GPIO.BCM)

        # Server Motor 
        GPIO.setup(17,GPIO.OUT) 
        # GPIO.setup(4,GPIO.OUT)

        pwm_motor_left = GPIO.PWM(17,50)
        # pwm_motor_right = GPIO.PWM(4,50)

        pwm_motor_left.start(0)
        # pwm_motor_right.start(0)

        # IR sensor
        #GPIO.setup(22, GPIO.IN,pull_up_down = GPIO.PUD_UP)
        GPIO.setup(27, GPIO.IN,pull_up_down = GPIO.PUD_UP)

        IR90_status = GPIO.input(27)
        #IR95_status = GPIO.input(22)



        #     print("IR95_status : " , IR95_status )
            
        print("IR90_status : " , IR90_status )
            
        if(IR90_status == 1 and msg != "b'1'"):
            IR90_status = GPIO.input(27)
            print("IR sensor not yet 90% ")
            cnt = 0
            for a in range (8):
                pwm_motor_left.start(7.5)
                print("Motor Open")
                pwm_motor_left.ChangeDutyCycle(7.5)#
            #             pwm_motor_right.ChangeDutyCycle(8)#
                time.sleep(0.1)
            pwm_motor_left.stop(7.5)

            time.sleep(3)


            for b in range (5):
                pwm_motor_left.start(4)

                print("Motor Close")
                pwm_motor_left.ChangeDutyCycle(4)
            #             pwm_motor_right.ChangeDutyCycle(4)
                time.sleep(0.1)
            pwm_motor_left.stop(4)
                
                
            
        elif(IR90_status == 0 ):
            IR90_status = GPIO.input(27)

            print ("Motor stop")
            pwm_motor_left.stop(0)
            for cnt in range(8):
                time.sleep(1)
                print(cnt)
            if(cnt > 5):
                print("enter")
                        # Account infomation load
                gmailUser = 'ntustchen0426@gmail.com'
                gmailPasswd = 'ynhwgalddlohwjxq'
                to = ['ntustchen0426@gmail.com']

                        # Create message
                emails = [t.split(',') for t in to]
                message = MIMEText('The capacity of the trashcan reaches 90%, please  clean it !!', 'plain', 'utf-8')
                message['Subject'] = 'Cleaning Notice !!'
                message['From'] = gmailUser
                message['To'] = ','.join(to)

                        # Set smtp
                smtp = smtplib.SMTP("smtp.gmail.com:587")
                smtp.ehlo()
                smtp.starttls()
                smtp.login(gmailUser, gmailPasswd)

                        # Send msil
                smtp.sendmail(message['From'], message['To'], message.as_string())
                print('Send mails OK!')
                cnt=0
        

if __name__ == '__main__':
    serv = UDPServer(('192.168.43.12', 9930), TimeHandler)
    serv.serve_forever()
