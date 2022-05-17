FROM ubuntu:18.04 as builder
LABEL maintainer=MagnaChain \
    version=0.0.1 \
    desp= DojoChain Docker image builder'
WORKDIR /root

#copy code to docker
COPY . /root/code

# setup ENV
RUN pwd \ 
# && mv /etc/apt/sources.list /etc/apt/sources.list.bak \
# && echo "deb http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse" >> /etc/apt/sources.list \
# && echo "deb http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse" >> /etc/apt/sources.list \
# && echo "deb http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse" >> /etc/apt/sources.list \
# && echo "deb-src http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse" >> /etc/apt/sources.list \
# && echo "deb http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse" >> /etc/apt/sources.list \
# && echo "deb-src http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse" >> /etc/apt/sources.list \
# && echo "deb-src http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse" >> /etc/apt/sources.list \
# && echo "deb http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse" >> /etc/apt/sources.list \
# && echo "deb-src http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse" >> /etc/apt/sources.list \
&& apt-get update \
&& apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils -y \
&& apt-get install libboost-system-dev libboost-filesystem-dev libboost-chrono-dev libboost-program-options-dev libboost-test-dev libboost-thread-dev libboost-iostreams-dev -y \
&& apt-get install software-properties-common -y \
&& add-apt-repository ppa:bitcoin/bitcoin \
&& apt-get update \
&& apt-get install libdb4.8-dev libdb4.8++-dev -y \
&& apt-get install libminiupnpc-dev -y \
&& apt-get install libzmq3-dev -y \
&& cd /root/code \
&& sh ./autogen.sh \
&& ./configure --without-gui \
&& make \
&& mkdir -p /root/dist \
&& perl ./docker_deploy.pl /root/code /root/dist
#ENV done
# RUN cd /root/code \
# && sh ./autogen.sh \
# && ./configure --without-gui \
# && make \
# && mkdir -p /root/dist \
# && perl ./docker_deploy.pl /root/dist \
FROM ubuntu:18.04 as result
WORKDIR /root
ENV APP=/root/app
ENV CHAIN_DATA=${APP}/blocks
ENV PATH ${APP}:$PATH
EXPOSE 8332

COPY --from=builder /root/dist /root/app/
COPY --from=builder /root/code/docker-entrypoint.sh /usr/local/bin/
# COPY ./app /root/app/
# COPY docker-entrypoint.sh /usr/local/bin/

RUN cd ${APP} \
&& ls -l \
&& chmod +x ${APP}/magnachaind ${APP}/magnachain-cli /usr/local/bin/docker-entrypoint.sh \
&&  mkdir -p blocks/main blocks/side \
&& echo ${APP} >> /etc/ld.so.conf.d/app.conf \
&& ldconfig
#TODO HEALTHCHECK
# HEALTHCHECK    

ENTRYPOINT [ "docker-entrypoint.sh","dojochaind"]
#   printtoconsole just for debug
# CMD [ "-printtoconsole", "-datadir=/root/app/blocks/main" ]
CMD [ "-datadir=/root/app/blocks/main" ]