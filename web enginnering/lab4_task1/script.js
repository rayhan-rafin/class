document.getElementById('registrationForm').addEventListener('submit', function (event) {
  event.preventDefault();

  let valid = true;

  // Name Validation
  const name = document.getElementById('name').value;
  if (name === '' || !/^[a-zA-Z ]+$/.test(name)) {
    document.getElementById('nameError').textContent = 'Please enter a valid name.';
    valid = false;
  } else {
    document.getElementById('nameError').textContent = '';
  }

  //email validation
  const email = document.getElementById('email').value;
  if (email === '' || !/^\S+\@\S+\.\S{3}$/.test(email)) {                              //regex changed
    document.getElementById('emailError').textContent = 'Please enter a valid email.';
    valid = false;
  } else {
    document.getElementById('emailError').textContent = '';
  }

  // Password Validation
  const password = document.getElementById('password').value;
  const confirmPassword = document.getElementById('confirmPassword').value;
  const passwordError = document.getElementById('passwordError');
  const confirmPasswordError = document.getElementById('confirmPasswordError');
  if (password.length < 8 || !/[A-Z]/.test(password) || !/[a-z]/.test(password) || !/[0-9]/.test(password)) {
    passwordError.textContent = 'Password must be at least 8 characters and include uppercase, lowercase, and a number.';
    valid = false;
  } else {
    passwordError.textContent = '';
  }
  if (password !== confirmPassword) {
    confirmPasswordError.textContent = 'Passwords do not match.';
    valid = false;
  } else {
    confirmPasswordError.textContent = '';
  }

  // Phone Validation
  const phone = document.getElementById('phone').value;
  if (phone === '' || !/^01\d{9}$/.test(phone)) {                                      // BD starts with 01 and total 11 digits
    document.getElementById('phoneError').textContent = 'Please enter a valid 11-digit phone number.';
    valid = false;
  } else {
    document.getElementById('phoneError').textContent = '';
  }

  // Age Validation
  const age = document.getElementById('age').value;
  if (age < 18 || age > 100) {
    document.getElementById('ageError').textContent = 'Please enter a valid age between 18 and 100.';
    valid = false;
  } else {
    document.getElementById('ageError').textContent = '';
  }

  // Gender Validation
  const genderMale = document.getElementById('male').checked;
  const genderFemale = document.getElementById('female').checked;
  if (!genderMale && !genderFemale) {
    document.getElementById('genderError').textContent = 'Please select your gender.';
    valid = false;
  } else {
    document.getElementById('genderError').textContent = '';
  }

  // Website Validation
  const website = document.getElementById('website').value;
  if (website === '' || !/^https\S+$/.test(website)) {                //https check
    document.getElementById('websiteError').textContent = 'Please enter a valid website URL.';
    valid = false;
  } else {
    document.getElementById('websiteError').textContent = '';
  }

  // Terms and Conditions Validation
  const terms = document.getElementById('terms').checked;
  if (!terms) {
    document.getElementById('termsError').textContent = 'You must agree to the terms and conditions.';
    valid = false;
  } else {
    document.getElementById('termsError').textContent = '';
  }

  // Final Validation Check
  if (valid) {
    alert('Form submitted successfully!');
    // You can send the form data to the server here
  }
  else {
    alert('Wrong form');               //wrong form
  }
});
