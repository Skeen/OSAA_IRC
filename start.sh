tail -f a.log | sed -u "s/å/aa/g" | sed -u "s/æ/ae/g" | sed -u "s/ø/oe/g" | ./irc /dev/ttyACM0
