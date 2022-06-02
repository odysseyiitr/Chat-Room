require 'socket'

s = TCPSocket.new 'localhost', 8989

s.write("example.txt\n")

s.each_line do |line|
    puts line
end

s.close