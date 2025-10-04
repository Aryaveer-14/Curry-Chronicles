document.addEventListener('DOMContentLoaded', function() {
    // --- Idea 2: Initialize Animate on Scroll ---
    AOS.init({
        once: true, // Whether animation should happen only once - while scrolling down
        duration: 450, // reduced animation duration for snappier feel
        easing: 'ease-in-out', // default easing for AOS animations
    });

    // --- Active Nav Link Styling ---
    const currentPage = window.location.pathname.split('/').pop() || 'index.html';
    const navLinks = document.querySelectorAll('header nav .nav-link');

    navLinks.forEach(link => {
        const linkPage = link.getAttribute('href');
        if (linkPage === currentPage) {
            link.classList.add('active');
        }
    });

    // --- Idea 5: Smooth Page Transitions ---
    const transitionEl = document.querySelector('.page-transition');

    // On page load, fade the transition layer out
    window.onload = () => {
        if (transitionEl) {
            transitionEl.classList.add('is-active');
        }
    };

    // Before navigating to a new page, fade the transition layer in
    document.querySelectorAll('a').forEach(link => {
        link.addEventListener('click', function(e) {
            const href = this.getAttribute('href');
            // Check if it's a valid, internal link and not a hash link
            if (href && href[0] !== '#' && href.indexOf('mailto:') === -1 && href.indexOf('tel:') === -1) {
                e.preventDefault(); // Stop the browser from navigating immediately
                if (transitionEl) {
                    transitionEl.classList.remove('is-active');
                }

                // After the transition animation, navigate to the new page
                setTimeout(() => {
                    window.location = href;
                }, 300); // shorter transition time to match CSS
            }
        });
    });
});
