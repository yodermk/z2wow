# z2wow - Zero To Wow!

## What is it?

This is an experimental project to create a publishing/workgroup server in modern C++.  There are various goals:

* Be as fast as possible! Page loads should be almost instantaneous.
* Explore data structures in C++ to support this goal. No database will be used; rather just in-memory
structures and the filesystem for storage.
* Explore features and usability ideas that other solutions don't provide. Innovate!
* Show that modern C++ is a fine web development language and has all the great features of the newfangled
languages.

## Status

Nothing yet.  A bit of basic structure code.  You won't use it anytime soon.

## What will it provide?

Goals include, from highest priority to crazy "maybe someday" ideas:

* Blog
* Photo gallery
* Discussion forums (adding discussion to the above)
* Notifications that expire when appropriate
* Realtime chat
* Federation to other sites
* Wiki
* Scrum board

## Unique features

There is an itch I've been wanting to scratch for a long time.  Corporate communications largely *suck*
in that the same message is posted in many different places, and often people have to deal with it even
after it expires.

The notification system mentioned above will allow a post to a hierarchy of users you specify (for example,
those in Texas), and expiring either at a specific date or expire-on-demand.  For example, say you need a ride
to the airport.  With a mailing list, you'd send the request by email, you'd get an offer, and then people
on future shifts will still see and have to delete the email.  Here, you remove it as soon as you have the
offer, saving everyone else time.

Something I want to do in the photo gallery is have an annotation feature.  For each photo, it should be
possible to write snippets of text that point to specific spots on the photo, and the viewer would be able
to move back and forth through the annotations.

I want to see more innovation like that.  Bring your ideas!

## Architecture

It is built on:

* Drogon, the C++ web framework
* Facebook Folly, for fast algorithms

It will run in a single multithreaded process.  Yes, I know this is very much unlike the microservice
architecture that most things are headed towards.  That's OK.

There will be a write log for durability.

Whenever anything is updated (forum post or whatever), the in-memory structure will be modified first.
Then the write log is updated.  Finally, the on-disk structure for the thing will be lazily updated.

The log will be shipable to other sites for a warm standby in case of primary node failure.  It will
also be used to federate portions of the site to other z2wow installations.  For example, a single
discussion forum may be shared among 5 different z2wow sites.

Users and groups will be able to be placed in different hierarchies; for example by location
(everyone in US -> everyone in Texas -> everyone in San Antonio), or by department (Operations
-> Support), or however you want.

### What about scalability?

Most "cloudy" applications scale horizontally with many load-balanced nodes.  This is different
in that the architecture allows only one active node.  Scalability will thus be vertical:  If you
need more power, you need a bigger computer!  However, you can buy or build with commodity parts
a server with up to 1TB of RAM, 64 CPU cores, and many terabytes of storage.  It will be a while
before this is validated, but I believe such a setup should easily serve an organization with
hundreds of thousands of users, with at least tens of thousands active at the same time.  Especially
given that we're writing in C++ with an explicit goal of optimization. 

## Why the name?

Because z2wow.com was available. :) And it's pretty easy to remember. I hope it also implies speed.
Really, what name these days *does* mean much? :/

## Contributing

I'd love to see a coding community build around this.  If that happens, I don't think reaching
all the stated features will be a stretch.  I'd be willing to help mentor.

All contributions shall be licensed under the GNU General Public License version 3 or later and
owned by their respective contributors, thus guaranteeing that the
license will never change, and will not be assimilated into some proprietary product without
changes being put back in the open, sort of like the Linux kernel.

If you want to hire me to work on it full time, I'm yoderm at gmail.  Hit me up.  :D

## Compiling and running

Coming soon...  Though if you know how to use CMake, and install Drogon and Folly, you're
about there.

