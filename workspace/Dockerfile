FROM alpine:3.7
MAINTAINER WILDRAGE<i@wildrage.xyz>

ENV GOAL=google_and_zhwikipedia \
    DOMAIN=google.nekomio.xyz

RUN apk --no-cache add gcc g++ git python3 python3-dev libc-dev                                  && \
    pip3 install --upgrade --no-cache-dir pip && \
    pip3 install --no-cache-dir gunicorn gevent requests flask cchardet fastcache lru-dict    && \
    git clone -b v0.30-dev https://github.com/HZoi-WildRage/zmirror /zmirror --depth 1            && \
    apk del --purge gcc g++ git libc-dev      && \
    rm -rf /src /zmirror/.git
    
WORKDIR /zmirror
EXPOSE  80

CMD cp more_configs/config_${GOAL}.py config.py && \
    sed -i "s/\'127.0.0.1\'/\'tmp_replace\'/g" config.py && \
    sed -i "s/tmp_replace/${DOMAIN}/g" config.py && \
    cat "verbose_level = 2" >>config.py && \
    gunicorn --bind 0.0.0.0:80 --workers 2 --worker-connections 100 wsgi:application