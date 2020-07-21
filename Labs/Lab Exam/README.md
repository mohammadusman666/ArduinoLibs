# Lab Exam (Store Data on Ubuntu Server through Node MCU)

The lab exam consists of five parts LabTask1, LabTask2, LabTask3, LabTask4 and LabTask5.

# Lab Tasks

## LabTask1:
In this LabTask, we had to create a database in mysql server running on Ubuntu Server. Then, we had to create a table which should have the following fields (id, status, dt, tm).

## LabTask2:
In this LabTask, we had to write a php file on the Server that should insert status, date and time in the table. We had to test the connection between the table and the php file by sending a request.

## LabTask3:
In this LabTask,we just had to clear all the entries in the table from within the Server.

## LabTask4:
In this LabTask, we had to write code on the Node MCU that should make an LED ON/OFF using a push button. Once the LED is ON, it will turn OFF only when the user presses the button again and vice versa.

## LabTask5:
In this LabTask, we had to extend the code written in the above task sp that the Node MCU connects with the Server. Now, on each button press, we had to store the LED status along with date and time in the database on the Server through the Node MCU by making a POST request.

# LAMP Stack:
- Install Apache 2.4 from the Ubuntu repository and start
    - `sudo apt install apache2`
    - `/etc/init.d/apache2 start`
- Install the mysql-server package
    - `sudo apt install mysql-server`
- Install PHP, the PHP Extension and Application Repository, Apache support, and MySQL support
    - `sudo apt install php7.2 libapache2-mod-php7.2 php-mysql`
- Install the MySQL client by using the Ubuntu package manager
    - `sudo apt-get install mysql-client`
    - During the installation process you will be prompted to enter a password for the MySQL root user. Once the installation is complete, the MySQL server should be started automatically. You can run the following command from a terminal prompt to check whether the MySQL server is running
    - `sudo netstat -tap | grep mysql`
    - When you run this command, you should see the following line or something similar
    - `tcp 0 0 localhost.localdomain:mysql *:* LISTEN -`
    - If the server is not running correctly, you can type the following command to start it:
    - `sudo /etc/init.d/mysql restart`

# Connectivity Issues:
- FCC’s Wifi was not assigning an IP to our Ubuntu Server VM even on Bridge Network settings
- Solution: Used a hotspot from Mobile and connected our laptop to it instead of FCC’s Wifi
