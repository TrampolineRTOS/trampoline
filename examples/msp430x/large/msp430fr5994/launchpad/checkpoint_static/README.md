# Static Checkpoint example

This application is a simple example of static checkpoint. It compute the fibonacci sequence, and whenever the S2 button is pressed, a checkpoint is performed.
If you restart the application using the S3 button, the application runs from the last checkpoint. Use S1 and S3 to perform a cold startup, and restart the application without using the last checkpoint.

Configure the application with

`
goil --target=msp430x/large/msp430fr5994/launchpad --templates=../../../../../../goil/templates/ checkpoint_static.oil
`
