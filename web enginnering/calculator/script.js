function getDate(){
    const DOB = new Date (document.getElementById("Bdate").value);
    const current = new Date ("02-08-2025");
    let age = current.getFullYear() - DOB.getFullYear();
    console.log(age)
    document.getElementById("output").textContent = `output age is ${age}`;
}