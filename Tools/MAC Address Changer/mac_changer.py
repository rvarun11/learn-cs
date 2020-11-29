import subprocess
import optparse

def change_mac(interface,new_mac):
    subprocess.call(["ifconfig",interface,"down"])
    subprocess.call(["ifconfig",interface,"hw","ether",new_mac])
    subprocess.call(["ifconfig",interface,"up"])

def get_args():
    parser = optparse.OptionParser()
    parser.add_option("-i","--interace",dest="interface",help="Enter the Interface whose MAC Address you want to change")
    parser.add_option("-m","--mac",dest="new_mac",help="Enter the new MAC Address")
    (options, arguements) = parser.parse_args()
    
    if not options.interface:
        parser.error("Please specify an Interface, use --help for more info.")
    elif not options.new_mac:
        parser.error("Please specify a MAC Address, use --help for more info.")

    return options

options = get_args()
# change_mac(options.interface,options.new_mac)

#Reading the output from the ifconfig command with the reqd interface
res = subprocess.check_output(["ifconfig",options.interface])


### Subprocess Call - Insecure Way, prone to Injections
# subprocess.call("ifconfig" + interface + " down", shell=True)
# subprocess.call("ifconfig" + interface + " hw ether" + new_mac, shell=True)
# subprocess.call("ifconfig" + interface + " up", shell=True)
