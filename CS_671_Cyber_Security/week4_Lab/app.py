from flask import Flask, render_template, request, redirect, url_for, session
import random
import smtplib
import os

app = Flask(__name__)
app.secret_key = 'supersecretkey'

def send_otp(email, otp):
    try:
        sender_email = "aryanbhagat5702@gmail.com"  
        sender_password = "logi cwoj uywq lrvj"     
     
        server = smtplib.SMTP('smtp.gmail.com', 587)
        server.starttls()
        server.login(sender_email, sender_password)

        subject = "Your OTP Code"
        body = f"Your OTP code is {otp}"
        message = f"Subject: {subject}\n\n{body}"

        server.sendmail(sender_email, email, message)
        server.quit()
    except Exception as e:
        print(f"Failed to send email: {e}")


@app.route('/')
def login_page():
    return render_template('login.html')

@app.route('/send_otp', methods=['POST'])
def send_otp_route():
    netid = request.form['netid']
    email = request.form['email']


    otp = random.randint(100000, 999999)
    session['otp'] = otp
    session['email'] = email

    send_otp(email, otp)
    
    return redirect(url_for('verify_otp'))
@app.route('/verify_otp', methods=['GET', 'POST'])
def verify_otp():
    if request.method == 'POST':
        user_otp = request.form['otp']
        if int(user_otp) == session['otp']:
            return "OTP Verified! Welcome to your dashboard."
        else:
            return "Invalid OTP. Please try again."

    return '''
        <h2>Enter the OTP sent to your email</h2>
        <form method="POST">
            <label for="otp">OTP:</label>
            <input type="text" name="otp" required>
            <button type="submit">Verify OTP</button>
        </form>
    '''

if __name__ == '__main__':
    app.run(debug=True)
