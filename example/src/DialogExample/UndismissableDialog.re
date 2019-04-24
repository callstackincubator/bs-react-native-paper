open BsReactNative;
open BsReactNativePaper;
open Paper;

module Styles = {
  open Style;

  let view = style([flexDirection(Row), alignItems(Center)]);

  let indicator = style([marginRight(Pt(16.))]);
};

let component = ReasonReact.statelessComponent("UndismissableDialog");

let make = (~close, ~visible, _children) => {
  ...component,
  render: _self =>
    <Portal>
      <Dialog onDismiss=close visible dismissable=false>
        <Dialog.Title> {ReasonReact.string("Progress Dialog")} </Dialog.Title>
        <Dialog.Content>
          <Paragraph>
            {ReasonReact.string("This is an undismissable dialog!!")}
          </Paragraph>
        </Dialog.Content>
        <Dialog.Actions>
          <Button color="#009688" disabled=true onPress={_event => close()}>
            {ReasonReact.string("Disagree")}
          </Button>
          <Button onPress={_event => close()}>
            {ReasonReact.string("Agree")}
          </Button>
        </Dialog.Actions>
      </Dialog>
    </Portal>,
};
