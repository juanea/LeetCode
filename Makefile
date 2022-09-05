.DEFAULT_GOAL := help
SHELL := /bin/bash

help:
	@grep -E '^[0-9a-zA-Z_-]+:.*?## .*$$|(^#--)' $(MAKEFILE_LIST) \
	| awk 'BEGIN {FS = ":.*?## "}; {printf "\033[32m %-43s\033[0m %s\n", $$1, $$2}' \
	| sed -e 's/\[32m #-- /[33m/'

#-- Docker
.PHONY: docker-prune
clean:  ## Remove all unused images, do not promp for confirmation, prune all volumes
	docker system prune --force --all --volumes
