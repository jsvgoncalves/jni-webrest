# Contributing
## Overview
1. Guidelines
 1. Git commits
 2. Code style
 3. Submitting your changes (Pull Requests)
2. Modules
3. Release and tags planning

## Guidelines
Follow the guidelines here to contribute to this project.

### Git Commits

Please separate each logical change into a sepate commit (`$ git add file_name
-p` might be useful).
The only exception for this is when merging the changes into the master branch
(see the Submitting your changes section below).

Also, please use the following style when committing your changes

    ## Commit Title
    # 1. Prepend module name (see modules on section below)
    # 2. Separate with colon (:)
    # 3. Use max. of 50 chars
    # 4. Describe the changes using imperative mood
    # 5. Do not capitalize first word of the title
    # 6. Do not end with a dot (.), titles don't end with dots
    # e.g.:
    wrapper: Upgrade to OAuth2

    ## Commit Message Body
    # 1. Separate from title with an empty line
    # 2. Use max. of 72 chars per line of text
    # 3. Include necessary comments and explanations of what has changed and
    #    why the changes are needed, what are the setbacks and considerations
    #    that be taken into account, etc.
    # 4. Add each logical section below into bullet points or numbered list
    #    (specially if you're rebasing your changes to merge them upstream,
    #    see Submitting your changes section)
    # 5. Reference GitHub issues (when appropriate) using #id
    # 6. If you reference a commit, include the title of the commit as well
    # 7. See the commit messages as an e-mail with a title and body, format the
    #    body appropriately, e.g.: split it into paragraphs (empty line) if
    #    necessary.
    # e.g.:
    - Fixes this weird bug (closes #34) by removing the include of the given
      module and creating a wrapper, as to avoid future clashes and amending the
      changes introduced in commit #3fb1af (module_name: add this neat bug).

    Notes: Something else to take into consideration, with a nice and detailed
           explanation.

    ## Signatures
    # Leave an empty line.
    # Then, please, sign your commits.
    # Use one (or a combination) of the following:
    # Signed-off-by: Joao Goncalves <some-email@gmail.com>
    # Reviewed-by: Joao Goncalves <some-email@gmail.com>
    # Acked-by: Joao Goncalves <some-email@gmail.com>
    # Tested-by: Joao Goncalves <some-email@gmail.com>


Not all commit messages need to have an elaborated body, but every commit
message should have a title and a body.

You can read more about best practices for git collaboration below:
- https://www.kernel.org/doc/Documentation/SubmittingPatches
- http://chris.beams.io/posts/git-commit/

You can also use a template for your git commits, see:
- https://github.com/jsvgoncalves/dotfiles/tree/master/git


### Code Style

Please follow the appropriate coding style for each language, i.e. Java, C++, XML etc.
Please lint your code to make sure you're doing your code style right.

Comment your code. Really. Obvious comments are not necessary, but a brief
explanation of the decision process or the potential impacts of each decision
are something **you** will thank yourself for having in the future.

Use intelligible variable names, avoid naming your variables `a, b, fqd` etc.

### Submitting your changes (Pull Requests)

When you've made your changes and pushed them into a branch in your fork,
please submit a Pull Request against `dev`.

## Modules

A list of the current modules of the app is below, use this to format your git
commit titles.

### docs

Changes on the project's documentation, including .md files.

### app

Changes to the general app configuration, i.e. permissions, builds, etc

### cpp

Changes related to integrating native code into the app

### wrapper

Changes related to the wrapper for the API

### api

Changes related to the OpenShift API and all of it's internal mechanics

### views

Changes related to the views of the app

## Version (release/tag) planning

### v0.0.1
  - Use gradle build system
  - Call C++ code using JNI

### v0.0.2

- Include C/C++ external libraries
- Perform HTTP Requests (curl calls)
- Use OAuth to query API's

### v0.0.3
- Wrapping C Library into JNI
- Extract Openshift API into external library
- Remove libcurl dependency (openshift-cpp-library should depend on it instead)

### v0.1.0 - v0.x

All versions v0.x.y should implement API calls to OpenShift API and implement
them appropriately with the wrapper.

- v0.1.1 Should start with a simple set of calls for v3 API
- v0.1.2 Should add some minor changes to those calls or include a few more
- v0.2.x Should add significant improvements to API calls or to the amount of
  calls covered
- ...

### v1.0.0 - Deployable App
