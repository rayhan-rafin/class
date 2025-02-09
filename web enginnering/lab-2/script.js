const formHtml = `
  <form id="contactForm">
    <label for="name">Name:</label><br>
    <input type="text" id="name" name="name"><br>
    <label for="email">Email:</label><br>
    <input type="email" id="email" name="email"><br>
    <label for="message">Message:</label><br>
    <textarea id="message" name="message"></textarea><br>
    <button onclick="Data()"> Submit </button>
  </form>
`;

function getForm() {
    document.getElementById('getData').innerHTML = formHtml;
  }
  function Data(){
    const formData = {
        name: document.getElementById("name").value,
        email: document.getElementById("email").value,
        message: document.getElementById("message").value
    };
    console.log(formData);
  }
  