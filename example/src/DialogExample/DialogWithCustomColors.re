open BsReactNative;
open Paper;

module Styles = {
  open Style;

  let dialog = style([backgroundColor(String("#4A148C"))]);
  let paragraph = style([color(String("#ffffff"))]);
  let title = style([color(String("#ffffff"))]);
};

let component = ReasonReact.statelessComponent("DialogWithCustomColors");

let make = (~close, ~visible, _children) => {
  ...component,
  render: _self =>
    <Portal>
      <Dialog onDismiss=close visible style=Styles.dialog>
        <Dialog.Title style=Styles.title>
          {ReasonReact.string("Alert")}
        </Dialog.Title>
        <Dialog.Content>
          <Paragraph style=Styles.paragraph>
            {ReasonReact.string("This is a dialog with custom colors")}
          </Paragraph>
        </Dialog.Content>
        <Dialog.Actions>
          <Button color="#ffffff" onPress={_event => close()}>
            {ReasonReact.string("OK")}
          </Button>
        </Dialog.Actions>
      </Dialog>
    </Portal>,
};
