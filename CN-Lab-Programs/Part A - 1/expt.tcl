# Simulate a 3 nodes point to point network with duplex links b/w them. Set the queue size vary the bw and find the number of packets dropped
set ns [new Simulator]

# Open a new file for nam trace
set nf [open out.nam w]
$ns namtrace-all $nf

# Open a new file to log trace
set tf [open out.tr w]
$ns trace-all $tf

#Body of the finish procedure
proc finish {} {
        global ns nf tf
        $ns flush-trace
        close $nf
	close $tf
	# Used for Open the Nam window and & is used for running the task in the bg
        exec nam out.nam &
        exit 0
}

#Create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

# $ns label $n0 "S"
# $ns label $n1 "R"

# Create links b/w the nodes
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail

$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n1 $n2 orient right

# Set the queue limit default is 50 packets
$ns queue-limit $n0 $n1 50
$ns queue-limit $n1 $n2 50

# Create transport Agent
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0

set null0 [new Agent/Null]
$ns attach-agent $n2 $null0

$udp0 set class_ 1

$ns color 1 red

$ns connect $udp0 $null0

# Create an application to generate the traffic
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005

$cbr0 attach-agent $udp0

$ns 0.5 "$cbr0 start"
$ns 4.5 "$cbr0 stop"

$ns 5.0 "finish"

$ns run


