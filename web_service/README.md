# Web Service

Basic instructions for intro purposes.

## Installation of prerequisites

Make sure that you are able to install virtual environments for your Python programs.
```
sudo apt-get install virtualenv
```

Create a virtual environment, for example, here we create the `web` virtual environment:
```
virtualenv web
```

Enter the virtual environment.
```
source web/bin/activate
```

In the virtual environment, install the flask framework.
```
pip install Flask
```


## Running

If you are not in the virtual environment, enter it:
```
source web/bin/activate
```

Run the app either with
```
python app.py
```
or
```
flask run
```

## Accessing the Application

Once your application is running, you'll see output indicating that the development server is running. By default, your Flask application will be accessible at `http://127.0.0.1:5000/` or `http://localhost:5000/`.
Open a web browser and navigate to this URL to interact with your application.

## Stopping the Application

To stop the Flask development server, press `Ctrl+C` in the terminal where the application is running.

## Notes

The basic development server provided by Flask is for testing and development purposes. 
In a production environment, you would typically deploy your Flask application using a production-ready web server like Gunicorn or uWSGI and configure it for security and performance.
