.PHONY: test install-hooks

all: exercises

exercises:
	./scripts/build.sh

test:
	./scripts/tests.sh

install-hooks:
	./scripts/install-hooks.sh

clean:
	rm -rf build/
