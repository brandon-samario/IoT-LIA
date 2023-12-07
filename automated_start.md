# IoT System automated startup

To complete the configuration of your IoT System, it is necessary to ensure that the system is active at boot time.

Our task is to create and enable services to run the

- IoT Controller
- IoT Historian
- IoT Web Service


To create a service and enable it on a Raspberry Pi running the Raspberry Pi OS (formerly known as Raspbian), you can use systemd. systemd is a system and service manager for Linux, and it's the default init system on Raspberry Pi OS. Here's a step-by-step guide:

### 1. Create a Service File

Create a new service file for your application. Service files are typically stored in the `/etc/systemd/system/` directory and end with the `.service` extension. For example, let's create a service file for a hypothetical Python script:

```bash
sudo nano /etc/systemd/system/my_service.service
```

Add the following content to the file, adjusting the `ExecStart` line to point to your actual command:

```ini
[Unit]
Description=My Custom Service
After=network.target

[Service]
ExecStart=/path/to/python /path/to/your/script.py
WorkingDirectory=/path/to/your/script/directory
Restart=always
User=your_username

[Install]
WantedBy=multi-user.target
```

- **Description**: A description of your service.
- **After**: Specifies when the service should be started in relation to other services (in this case, after the network is up).
- **ExecStart**: The command that starts your service. Replace `/path/to/your/script.py` with the actual path to your script.
- **WorkingDirectory**: The working directory for your script.
- **Restart**: Specifies when the service should be restarted (in this case, always).
- **User**: The user under which the service should run.
- **WantedBy**: Specifies which target should include this service.

### 2. Save the Service File

Save the changes and exit the text editor (for nano, press `Ctrl` + `X`, then `Y`, and `Enter`).

### 3. Reload systemd

Reload systemd to make it aware of the new service:

```bash
sudo systemctl daemon-reload
```

### 4. Enable the Service

To start the service at boot, enable it:

```bash
sudo systemctl enable my_service
```

Replace `my_service` with the name you gave to your service file.

### 5. Start the Service

You can start the service manually for the first time:

```bash
sudo systemctl start my_service
```

### 6. Check the Status

To check the status of your service:

```bash
sudo systemctl status my_service
```

This should give you information about whether the service is running correctly.

Your service should now be running, and it will start automatically on boot.

# Specific IoT Controller System Configuration

For our system specifically, here is how I made it run with my username "username".

## Iot_Controller

Create a new service file for your application. Service files are typically stored in the `/etc/systemd/system/` directory and end with the `.service` extension. For example, let's create a service file for a hypothetical Python script:

```bash
sudo nano /etc/systemd/system/IoT_Controller.service
```

Add the following content to the file, adjusting the `ExecStart` line to point to your actual command:


```bash
[Unit]
Description=IoT Controller
After=network.target

[Service]
ExecStart=/usr/bin/python3 /home/username/IoT_Controller/IoT_Controller.py
WorkingDirectory=/home/username/IoT_Controller/
Restart=always
User=username

[Install]
WantedBy=multi-user.target
```

Save the changes and exit the text editor (for nano, press `Ctrl` + `X`, then `Y`, and `Enter`).

Reload systemd to make it aware of the new service:

```bash
sudo systemctl daemon-reload
```

To start the service at boot, enable it:

```bash
sudo systemctl enable IoT_Controller.service
```

You can start the service manually for the first time:

```bash
sudo systemctl start IoT_Controller.service
```

To check the status of your service:

```bash
sudo systemctl status IoT_Controller.service
```

## Historian

Create a new service file for your application. Service files are typically stored in the `/etc/systemd/system/` directory and end with the `.service` extension. For example, let's create a service file for a hypothetical Python script:

```bash
sudo nano /etc/systemd/system/IoT_Historian.service
```

Add the following content to the file, adjusting the `ExecStart` line to point to your actual command:

```bash
[Unit]
Description=IoT Historian
After=network.target

[Service]
ExecStart=/usr/bin/python3 /home/username/IoT_Controller/historian.py
WorkingDirectory=/home/username/IoT_Controller/
Restart=always
User=username

[Install]
WantedBy=multi-user.target
```

Save the changes and exit the text editor (for nano, press `Ctrl` + `X`, then `Y`, and `Enter`).

Reload systemd to make it aware of the new service:

```bash
sudo systemctl daemon-reload
```

To start the service at boot, enable it:

```bash
sudo systemctl enable IoT_Historian.service
```

You can start the service manually for the first time:

```bash
sudo systemctl start IoT_Historian.service
```

To check the status of your service:

```bash
sudo systemctl status IoT_Historian.service
```

## Web interface

Note that we should modify this with the configuration of Web servers for a production environment.

Create a new service file for your application. Service files are typically stored in the `/etc/systemd/system/` directory and end with the `.service` extension. For example, let's create a service file for a hypothetical Python script:

```bash
sudo nano /etc/systemd/system/IoT_Web.service
```

Add the following content to the file, adjusting the `ExecStart` line to point to your actual command:

```bash
[Unit]
Description=IoT Controller Web Interface
After=network.target

[Service]
ExecStart=/home/username/IoT_Controller/web_service/web/bin/python /home/username/IoT_Controller/web_service/app.py
WorkingDirectory=/home/username/IoT_Controller/web_service
Restart=always
User=username

[Install]
WantedBy=multi-user.target
```

Save the changes and exit the text editor (for nano, press `Ctrl` + `X`, then `Y`, and `Enter`).

Reload systemd to make it aware of the new service:

```bash
sudo systemctl daemon-reload
```

To start the service at boot, enable it:

```bash
sudo systemctl enable IoT_Web.service
```

You can start the service manually for the first time:

```bash
sudo systemctl start IoT_Web.service
```

To check the status of your service:

```bash
sudo systemctl status IoT_Web.service
```
