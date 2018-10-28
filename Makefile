all: exercises

exercises:
	./scripts/build.sh

test:
	./scripts/run-tests.sh

install-hooks:
	./scripts/install-hooks.sh

clean:
	rm -rf build/
