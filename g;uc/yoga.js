

const flightPath = {
    curviness: 1.25,
    autoRotate: true,
    values: [
        {x: 100, y:-20} ,
        {x:300, y:10},
        {x:200, y:100},
        {x:130, y:-100},
        {x:30, y:-360},
        {x: window.innerWidth, y:-500}
    ]
}

const tween = new TimelineLite();
tween.add(
    TweenLite.to(".anime",7,{
        bezier: flightPath,
        ease: Power1.easeInOut
    })
);

const controller = new ScrollMagic.Controller();

const scene = new ScrollMagic.Scene({
    triggerElement: ".animation",
    duration: 3000

})
.setTween(tween)
.addIndicators()
.addTo(controller);
