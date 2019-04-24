open BsReactNative;
open BsReactNativePaper;
open Paper;

module Styles = {
  open Style;

  let view = style([flexDirection(Row), alignItems(Center)]);

  let indicator = style([marginRight(Pt(16.))]);
};

let component = ReasonReact.statelessComponent("DialogWithLoadingIndicator");

let make = (~close, ~visible, _children) => {
  ...component,
  render: _self =>
    <Portal>
      <Dialog onDismiss=close visible>
        <Dialog.Title> {ReasonReact.string("Progress Dialog")} </Dialog.Title>
        <Dialog.Content>
          <View style=Styles.view>
            <ActivityIndicator
              color="#6200EE"
              size={
                switch (Platform.os()) {
                | Platform.Android => `exact(48)
                | _ => `large
                }
              }
              style=Styles.indicator
            />
            <Paragraph> {ReasonReact.string("Loading.....")} </Paragraph>
          </View>
        </Dialog.Content>
      </Dialog>
    </Portal>,
};
