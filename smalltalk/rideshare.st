"===============================================================================
Program: Ride Sharing System (Smalltalk)
Author: Sandesh Pokharel
==============================================================================="

Object subclass: Ride [
    | rideID pickupLocation dropoffLocation distance |

    Ride class >> newWithID: id pickup: pickup dropoff: dropoff distance: dist [
        ^ (self new)
            setRideID: id;
            setPickupLocation: pickup;
            setDropoffLocation: dropoff;
            setDistance: dist;
            yourself
    ]

    setRideID: id [ rideID := id ]
    setPickupLocation: pickup [ pickupLocation := pickup ]
    setDropoffLocation: dropoff [ dropoffLocation := dropoff ]
    setDistance: dist [ distance := dist ]

    rideID [ ^ rideID ]
    pickupLocation [ ^ pickupLocation ]
    dropoffLocation [ ^ dropoffLocation ]
    distance [ ^ distance ]

    fare [ ^ distance * 1.0 ]

    rideDetails [
        Transcript show: 'Ride ID: ', rideID; nl;
        show: 'Pickup: ', pickupLocation; nl;
        show: 'Dropoff: ', dropoffLocation; nl;
        show: 'Distance: ', distance printString, ' miles'; nl;
        show: 'Fare: $', (self fare) printString; nl;
        show: '-------------------------'; nl.
    ]
]

Ride subclass: StandardRide [
    fare [ ^ self distance * 1.5 ]
    rideDetails [
        Transcript show: 'Standard Ride'; nl.
        super rideDetails.
    ]
]

Ride subclass: PremiumRide [
    fare [ ^ self distance * 2.5 ]
    rideDetails [
        Transcript show: 'Premium Ride'; nl.
        super rideDetails.
    ]
]

Object subclass: Driver [
    | driverID name rating assignedRides |

    Driver class >> newWithID: id name: n rating: r [
        ^ (self new)
            setDriverID: id;
            setName: n;
            setRating: r;
            initRides;
            yourself
    ]

    setDriverID: id [ driverID := id ]
    setName: n [ name := n ]
    setRating: r [ rating := r ]  "We now pass string directly to avoid print issues"
    initRides [ assignedRides := OrderedCollection new ]

    addRide: ride [ assignedRides add: ride ]

    getDriverInfo [
        Transcript show: 'Driver ID: ', driverID, ', Name: ', name, ', Rating: ', rating; nl.
        Transcript show: 'Completed Rides:'; nl.
        assignedRides do: [:ride | ride rideDetails].
    ]
]

Object subclass: Rider [
    | riderID name requestedRides |

    Rider class >> newWithID: id name: n [
        ^ (self new)
            setRiderID: id;
            setName: n;
            initRides;
            yourself
    ]

    setRiderID: id [ riderID := id ]
    setName: n [ name := n ]
    initRides [ requestedRides := OrderedCollection new ]

    requestRide: ride [ requestedRides add: ride ]

    viewRides [
        Transcript show: 'Rider ID: ', riderID, ', Name: ', name; nl.
        Transcript show: 'Requested Rides:'; nl.
        requestedRides do: [:ride | ride rideDetails].
    ]
]

"============================= DEMO =============================="

r1 := StandardRide newWithID: 'RIDE001' pickup: 'Downtown' dropoff: 'Airport' distance: 10.
r2 := PremiumRide newWithID: 'RIDE002' pickup: 'Station' dropoff: 'Mall' distance: 7.5.

rideList := OrderedCollection new.
rideList add: r1.
rideList add: r2.

Transcript show: '=== All Rides (Polymorphism Demo) ==='; nl.
rideList do: [:ride | ride rideDetails].

"💥 FIXED: Pass rating as string to avoid Float printing bug"
driver := Driver newWithID: 'D001' name: 'Alice' rating: '4.8'.
driver addRide: r1.
driver addRide: r2.
driver getDriverInfo.

rider := Rider newWithID: 'U001' name: 'Bob'.
rider requestRide: r1.
rider requestRide: r2.
rider viewRides.

