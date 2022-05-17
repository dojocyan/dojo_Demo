#!/bin/bash
set -Eeuo pipefail
if [ -e  ${CHAIN_DATA}/main/ Dojochain.conf ];then
    echo "ignore config"
else
    echo "rpcuser=user" >> ${CHAIN_DATA}/main/ Dojochain.conf 
    echo "rpcpassword=pwd" >> ${CHAIN_DATA}/main/ Dojochain.conf 
    echo "rpcworkqueue=1000" >> ${CHAIN_DATA}/main/ Dojochain.conf 
    echo "rpcallowip=0.0.0.0/0" >> ${CHAIN_DATA}/main/ Dojochain.conf
fi
echo "--------------------------"
exec "$@"