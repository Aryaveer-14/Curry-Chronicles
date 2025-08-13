// Wait for the entire DOM to be loaded before running the script
document.addEventListener('DOMContentLoaded', () => {

    // --- Smooth Scrolling for Navigation Links ---
    // Select all anchor links that start with '#' (internal links)
    document.querySelectorAll('a[href^="#"]').forEach(anchor => {
        anchor.addEventListener('click', function (e) {
            e.preventDefault(); // Prevent default jump behavior

            // Get the target element using the href attribute
            const targetId = this.getAttribute('href').substring(1);
            const targetElement = document.getElementById(targetId);

            if (targetElement) {
                // Scroll smoothly to the target element
                targetElement.scrollIntoView({
                    behavior: 'smooth'
                });
            }
        });
    });

    // --- Search Bar Functionality ---
    const searchForm = document.querySelector('.search-bar form');
    const searchInput = document.querySelector('.search-bar input[type="text"]');

    if (searchForm) {
        searchForm.addEventListener('submit', function(e) {
            e.preventDefault(); // Prevent default form submission (page reload)

            const query = searchInput.value.trim(); // Get the search query and remove whitespace

            if (query) {
                // In a real application, you would send this query to a backend server
                // or redirect to a search results page.
                console.log('Searching for:', query);
                alert(`Searching for: "${query}"`); // Using alert for demonstration

                // Clear the search input after submission
                searchInput.value = '';
            } else {
                alert('Please enter a search term!');
            }
        });
    }

    // --- Form Submission Handling (Sign Up and Contact Forms) ---

    // Generic function to handle form submissions
    function handleFormSubmission(formSelector, formName) {
        const form = document.querySelector(formSelector);

        if (form) {
            form.addEventListener('submit', function(e) {
                e.preventDefault(); // Prevent default form submission

                // Collect form data (for demonstration purposes)
                const formData = new FormData(form);
                const data = {};
                for (let [key, value] of formData.entries()) {
                    data[key] = value;
                }

                console.log(`${formName} form submitted:`, data);
                alert(`Thank you for submitting the ${formName} form! Check the console for data.`);

                form.reset(); // Clear the form fields
            });
        }
    }

    // Apply the form submission handler to the specific forms
    handleFormSubmission('.signup-form', 'Sign Up');
    handleFormSubmission('.contact-form', 'Contact');

});
